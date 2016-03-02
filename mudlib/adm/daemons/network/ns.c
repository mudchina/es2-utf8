// Huthar's name service

#define log(a) log_file("ns.log",ctime(time())+":"+a)
//#define log(a) tell_object(find_player("huthar"),a)

#include <net/socket.h>
#include <net/daemons.h>

mapping sockets;
mapping muds;

void read_parse_line(int fd, string msg);
void do_lookup(int fd, string mud, string service);
void do_dump(int fd);

void connect_socket(int fd)
{
   sockets[fd] = "";
}

void read_parse_line(int fd, string msg)
{
   string cmd, arg, arg1, arg2;
   object ob;

   if(sscanf(msg, "CMD:%s %s", cmd, arg))
   {
      if(cmd == "LOOKUP")
      {
         if(arg == "ALL")
         {
            do_dump(fd);
            return;
         }
         if(!sscanf(arg,"%s %s", arg1, arg2))
         {
            arg1 = arg;
            arg2 = "DEFAULT";
         }
         do_lookup(fd, arg1, arg2);
      }
      else
      {
         socket_write(fd, "Unknown command\n");
      }
   }
}

void shutdown_socket(int fd)
{
   log("FD shutdown.\n");
   map_delete(sockets,fd);
}

create()
{
   sockets = ([]);
   muds = NAME_SERVER->query_data();
}

void do_lookup(int fd, string mud, string service)
{
   string address, port;

   address = (string)NAME_SERVER->get_host_name(mud);
   port = (int)NAME_SERVER->get_mudresource(mud, service)+"";

   if(address == "")
   {
      socket_write(fd, "NOT FOUND\n");
      return;
   }

   socket_write(fd, address+":"+port+"\n");
}

void do_dump(int fd)
{
   mapping muds;
   string *k;
   int i;

   muds = (mapping)NAME_SERVER->query_muds();
   k = keys(muds);

   for(i = 0; i < sizeof(k); i++)
   {
      if(k[i] == "DEFAULT")
         continue;
      socket_write(fd, k[i]+":"+muds[k[i]]["address"]);
      socket_write(fd,":"+muds[k[i]]["port"]+"\n");
   }
}
