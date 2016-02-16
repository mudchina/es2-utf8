/*
 * Intermud services daemon
 * Original author: Huthar@Portals
 * Rewritten: Blackthorn@Genocide (10/29/92)
 * Cleaned up and unflakified by Truilkan@Basis (11/21/92)
 * Removed a redundant map_delete() call - Truilkan (11/21/92)

 * 93-07-30 Grendel@tmi-2 Removed defines, replaced with inetd.h
 */
 
#include <config.h>
#include <net/daemons.h>
#include <net/socket.h>
#include <net/inetd.h>
#include <net/macros.h>

#define log(x) log_file("inetd", (x))

// function protypes
void possible_close(int id);
string read_socket(int id);
int write_socket(int id, string msg);
void load_services();
void create_listen_socket();
void close_socket(int id);
void close_callback(int fd);
void write_callback(int id);
void read_callback(int fd, string msg);
int create_socket(string dest);
int open_service(string mud, string svc, string *parms);
void process_incoming(int fd);

// globals
int listen_fd;
mapping sockets, service;

 // indexed on numerical socket id
 //  "incoming": incoming data waiting to be read
 //  "outgoing": outgoing data waiting to be written
 //  "owner": object that owns the socket
 //  "wcb_pending": a write callback is pending on this socket
 //  "closing": no further operations should be permitted on this socket
 //  "read_callback": name of the owner's read callback function 
 //  "close_callback": name of the owner's close callback function
 //  "service_callback": name of the owner's "service callback" function
 //  "fd": socket's file descriptor
 //  "service_desired": service that we want from the remote mapping service;
 // indexed on service name, contains string filename of server object
 
void
possible_close(int id)
{
   if (!sockets[id]) {
      return;
   }
   if (sockets[id]["closing"]) {
      if (!strlen(sockets[id]["outgoing"])
         && !strlen(sockets[id]["incoming"]))
      {
         socket_close(sockets[id]["fd"]);
      }
   }
}
 
string
read_socket(int id)
{
   int error;

   if (!sockets[id] || ((previous_object() != this_object())
      && (previous_object() != sockets[id]["owner"])))
   {
      log("read_socket: security violation on socket id " + id + "\n");
      return 0;                                                  
   }
   if (strlen(sockets[id]["incoming"]) > 0) {
      string rcv;

      rcv = sockets[id]["incoming"];
      sockets[id]["incoming"] = "";
      possible_close(id);
      return rcv;
   } else return 0;
}

int
write_socket(int id, string msg)
{
   int error;

   if (!sockets[id] || ((previous_object() != this_object())
      && (previous_object() != sockets[id]["owner"])))
   {
      log("write_socket: security violation on socket id " + id + "\n");
      return 0;
   }

   //  it used to check for "closing" status here, but we should first be
   //  allowed to empty out the "incoming" and "outgoing" buffers.
   //  Patch by Zazz@WizMud, 3/26/93.

   if (sockets[id]["wcb_pending"])  {
      sockets[id]["outgoing"] += msg;
   } else {
      error = socket_write(sockets[id]["fd"], msg);
      if (error != EESUCCESS) {
         // on some machines this happens *alot*
         if (error == EEALREADY) {
           sockets[id]["outgoing"] += msg;  // data *not* buffered
           sockets[id]["wcb_pending"] = 1;
         }
         if (error==EECALLBACK) {
            sockets[id]["wcb_pending"] = 1;
         } else return 0;
      }
   }
   // NOW check to see if the server has indicated it is through
   if (sockets[id]["closing"] == 1) {
      possible_close(id);   // will close iff buffers empty
      return 0;
   }
   return 1;
}
 
void
load_services()
{
   string file, *lines, svc;
   string path;
   int i;
 
   service = ([]);
   file = read_file(INETD_SERVICES);
   if (!file) {
      log("load_services: cannot read inetd services file "
         + INETD_SERVICES + "\n");
      return;
   }
   lines = explode(file, "\n");
   for (i = 0; i < sizeof(lines); i++) {
      if (lines[i] == "" || lines[i][0] == '#') continue;
      if (sscanf(lines[i], "%s %s", svc, path) != 2) {
         log("load_services: error in services file, line "
            + (i + 1) + "\n");
         continue;
      }
      service[svc] = path;
   }
}
 
void
create_listen_socket()
{
   int error;

   listen_fd = socket_create(STREAM, "read_callback", "close_callback");
   if (listen_fd < 0) {
      log("create_listen_socket: socket_create: " + 
         socket_error(listen_fd) + "\n");
      return;
   }
   error = socket_bind(listen_fd,
      (int)DNS_MASTER->get_mudresource(mud_nname(), "inetd"));
   if (error != EESUCCESS) {
      socket_close(listen_fd);
      log("create_listen_socket: socket_bind: " + 
         socket_error(listen_fd) + "\n");
      return;
   }
   error = socket_listen(listen_fd, "read_callback");
   if (error != EESUCCESS) {
      socket_close(listen_fd);
      log("create_listen_socket: socket_listen: " + 
         socket_error(listen_fd) + "\n");   
      return;
   }
}
 
void
close_socket(int id)
{
   if (!sockets[id] || ((previous_object() != this_object())
      && (previous_object() != sockets[id]["owner"])))
   {
      log("close_socket: security violation on socket id " + id + "\n");
      return 0;                                                  
   }
   sockets[id]["closing"] = 1;
   possible_close(id);
}
 
void
close_callback(int fd)
{
   if (fd == listen_fd) {
      log("close_callback: shutdown on listen fd " + fd + "\n");
      return;
   }
   if(sockets[fd]["owner"])
   call_other(sockets[fd]["owner"], sockets[fd]["close_callback"], fd);
   map_delete(sockets, fd); // nuke this puppy
}
 
void
write_callback(int id)
{
   sockets[id]["wcb_pending"] = 0;
   if (strlen(sockets[id]["outgoing"]) > 0) {
      string send;

      send = sockets[id]["outgoing"];
      sockets[id]["outgoing"] = "";
      this_object()->write_socket(id, send);
      possible_close(id);
   }
}
 
void read_callback(int fd, string msg)
{
   string tmp1, tmp2;

   if (fd == listen_fd) {
      int new_fd;

      new_fd = socket_accept(fd, "read_callback", "write_callback");
      if (new_fd < 0) {
         log("read_callback: socket_accept: " + socket_error(new_fd) + "\n");
         return;
      }
      sockets[new_fd] = allocate_mapping(8);
      sockets[new_fd]["fd"] = new_fd;
      sockets[new_fd]["incoming"] = "";
      sockets[new_fd]["outgoing"] = "";
      sockets[new_fd]["read_callback"] = "read_callback";
      sockets[new_fd]["close_callback"] = "close_callback";
      sockets[new_fd]["service_callback"] = "service_callback";
      sockets[new_fd]["service_status"] = AWAITING_SERVICE;
      write_socket(new_fd, "SERVICE?\n");
      return;
   }
   if (!sockets[fd]) {
      log("read_callback: callback on unknown socket fd " + fd + "\n");
      return;
   }
   sockets[fd]["incoming"] += msg;
   while (sscanf(sockets[fd]["incoming"], "%s\n%s", tmp1, tmp2) == 2) {
      sockets[fd]["incoming"] = tmp1 + "\n";
      process_incoming(fd);
      sockets[fd]["incoming"] = tmp2;
   }
}
 
int
create_socket(string dest)
{
   int fd, error;

   fd = socket_create(STREAM, "read_callback", "close_callback");
   if (fd < 0) {
      log("create_socket: socket_create: " + socket_error(fd) + "\n");
      return -1;
   }
   error = socket_connect(fd, dest, "read_callback", "write_callback");
   if (error != EESUCCESS) {
      socket_close(fd);
      log("create_socket: socket_connect: " + socket_error(error) + "\n");
      return -1;
   }  
   sockets[fd] = allocate_mapping(8);
   sockets[fd]["fd"] = fd;
   sockets[fd]["incoming"] = "";
   sockets[fd]["owner"] = previous_object();
   sockets[fd]["outgoing"] = "";
   sockets[fd]["read_callback"] = "read_callback";
   sockets[fd]["close_callback"] = "close_callback";
   sockets[fd]["service_callback"] = "service_callback";
   return fd;
}
 
int
open_service(string mud, string svc, string *parms)
{
   int id;
   string address;

   address = INETD_PORT(mud);
   if (!address) {
      return -1;
   }
   id = create_socket(address);
   if (id < 0) {
      return id;
   }
   sockets[id]["service_status"] = AWAITING_CONNECT_ACK;
   sockets[id]["service_desired"] = 
      svc + (parms ? (" " + implode(parms, " ")) : "");
   return id;
}
 
void process_incoming(int fd)
{
   object ob;
   int error, l;
   string msg, svc, *parms;
 
   msg = this_object()->read_socket(fd);
   switch (sockets[fd]["service_status"]) {
      case AWAITING_CONNECT_ACK:
         if (msg == "SERVICE?\n") {
            this_object()->write_socket(fd, sockets[fd]["service_desired"]
               + "\n");
            sockets[fd]["service_status"] = AWAITING_DATA;
            call_other(sockets[fd]["owner"],
               sockets[fd]["service_callback"], fd);
            return;
         } 
      break;
      case AWAITING_DATA:
         call_other(sockets[fd]["owner"],
            sockets[fd]["read_callback"], fd, msg);
      break;
      case AWAITING_SERVICE:
         svc = msg[0..-2];
         parms = explode(svc, " ");
         if (!service[parms[0]]) {
            write_socket(fd, "SERVICE NOT AVAILABLE\n");
            close_socket(fd);
         }
         svc = parms[0];
         service[svc]->dummy();
         sockets[fd]["owner"] = find_object(service[svc]);
         sockets[fd]["service_status"] = AWAITING_DATA;
         service[svc]->service_request(fd, parms[1..sizeof(parms)-1]);
      break;
      default :
      break;
   }
}

void
create()
{
   seteuid(getuid(this_object()));
   sockets = ([]);
   load_services();
   create_listen_socket();
}

/*
  client:
     To initiate, use 
     INETD->open_service(string mudname, string servicename, string *parms)
     The id of the socket assigned to your service request will be returned, 
     or -1 for failure.  the calling object is used as the owner.
     The function service_callback(id) will be called in the owner when
     the service is open and ready for data transfer.
 
  server:           
    service_request(int id, string *parms) will be called in the server 
     object of the appropriate service whenever a request for that 
     service is made.  The server object is set as owner.
    
  both:
    INETD->write_socket(int id, string msg) sends text out the socket
    the function read_callback(int id, string msg) will be called in the 
    owner when data is received.
    The function close_callback(id) will be called in the owner if the socket
    closes from the other end, INETD->close_socket(int id) can be used to 
    close it from our end
*/

mapping query_sockets()
{
  if(member_group(geteuid(previous_object()),"admin"))
    return sockets;
  return 0;
}

mapping query_service()
{
  if(member_group(geteuid(previous_object()),"admin"))
    return service;
  return 0;
}
