 
//	File	:  /adm/daemons/pingd.c
//	Creator	:  Zazz@WizMud  (4/93)
//	Updated	:  Watcher@TMI  (4/9/93)  for TMI-2 mudlib and call_out
//		    removal on socket_close.
//
//	This is the ping server.  It opens the socket and requests
//	service.  When a response is received, it closes the connection.

#include <mudlib.h>
#include <net/socket.h>
#include <uid.h>
#include <net/daemons.h>

inherit DAEMON;
 
#define TIME_OUT_TIME  30
#define LOG_FILE       "PS"
#define log(xx)        log_file( LOG_FILE, xx )
#define addr(xx)       (string)DNS_MASTER->get_host_name( xx ) + " " + \
                       (int)DNS_MASTER->get_mudresource( xx , "inetd" )

static int strip_callout(int num);
int notify_player( int s, string msg );
int time_data( int s );
void close_socket( int s );

mapping pings;


void create() {
   seteuid( getuid() );
   pings = ([ ]);
}

int ping_request(string mud) {  // called by the _ping.c
   int s, error;
   string address;

   if (!mud || mud=="") return 0;
   address = addr( mud );
   if (!address || address=="" || address == " 0") return 0; 
   
   s = socket_create( STREAM, "read_callback", "close_callback" );
 
   if (s<0) {
      log("ping_request, socket_create: "+socket_error(s)+"\n");
      return -1;
   }

   error = socket_connect( s, address, "read_callback", "write_callback" );
   if(error<0) {
      log("ping_request, socket_connect: "+socket_error( error )+"\n");
      socket_close( s );  // dammit!
      return -1;
   }

   pings[s] = allocate_mapping(3);
   pings[s]["fd"] = s;
   pings[s]["time_sent"] = time();
   pings[s]["mudname"] = mud;
   pings[s]["object"] = previous_object();       // eek.
   call_out("time_out", TIME_OUT_TIME, s );
   return 1;                                 // ok, now we wait...:)
}

void read_callback( int fd, string mess ) {  // the only one that counts
 
  pings[fd]["object"] -> callback( pings[fd]["mudname"], 1 );
   close_socket( fd );  // this will sever connection
   return;
}

void time_out( int fd ) {
   if(pings[fd]["fd"]) {
  pings[fd]["object"] -> callback( pings[fd]["mudname"], 0 );
      close_socket( fd );
   }
   return;
}

void close_callback( int fd ) {    // this means *premature* closure
   if(!pings[fd]["fd"]) return;    // Hmm...why would this happen? 
  pings[fd]["object"] -> callback( pings[fd]["mudname"], 0 );

   close_socket( fd );
   return;
}

int time_data( int fd ) {
   if(!pings[fd]["time_sent"]) return -1;
   return (time() - pings[fd]["time_sent"]);
}

void close_socket( int fd ) {
   int error;
   if(!pings[fd]["fd"]) return 0;
   strip_callout( fd );
 
   error = socket_close( fd );
   if(error<0) {
      log("close_socket, socket_close: "+socket_error(error)+"\n");
      return;
   }
   map_delete( pings, fd );
   return;
}

static int strip_callout(int num) {
   mixed *info;
   int loop;

   info = call_out_info();
 
   while(remove_call_out("time_out") != -1) { }
 
   for(loop=0; loop<sizeof(loop); loop++) {
     if(info[loop][0] != this_object())  continue;
 
     if(info[loop][3] != num)  
	call_out("time_out", info[loop][2], info[loop][3]);

   }

return 1; }
 
