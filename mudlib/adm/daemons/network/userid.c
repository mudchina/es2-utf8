#pragma save_binary

//      File    :  /adm/daemons/userid.c
//	Creator	:  Watcher@TMI-2  (5/93)
//
//	Based on the general design concepts of Pinkfish@DiscWorld's
//	IDENT server.  All Bing Pinkfish!!
//
//      This daemon will connect up to an authorization daemon and
//      and return a user's login name.

#include <priv.h>
#include <config.h>
#include <net/socket.h>
#include <net/daemons.h>
#include <mudlib.h>

inherit DAEMON ;
 
mapping requests;

void create() {
	seteuid(getuid(this_object()));
	requests = ([ ]);
}

void query_userid() {
   string socket, address;
   int port, line, tmp;

   //	Check to make sure we have pulled the local port from 
   //	the mud's name server.
 
   //	Get socket source info from the requesting user.
 
   socket = socket_address( previous_object() );
 
   if(!socket)  return;
 
   //	Parse out address and port from source socket
 
   if(sscanf(socket, "%s %d", address, port) != 2)  return;
 
   line = socket_create(STREAM, "socket_shutdown");

   if(line < 0)  return;
 
   if(socket_connect(line, address + " 113","receive_data","write_data") < 0) {
	previous_object()->query_link()->set("userid", 0);
	socket_close(line);
   return ; }
 
   requests[line] = ({ previous_object(), port });
 
}
 
void write_data(int line) {
   int ret;

   //	Okay, send the userid request protocol.
 
   ret = socket_write(line, requests[line][1] + "," + mud_port() + "\n");
 
   //	Hmmm....is there an IDENT server listening ?
 
   if(ret < 0) {
     socket_close(line);
     requests[line][0]->query_link()->set("userid", 0);
     map_delete(requests, line);
   }

}
 
void receive_data(int line, string info) {
   string tmp, machine, name, userid;
 
   //	Okay ... we got a response. Are we sure its from the driver
   //	and is the info we actually want...
 
   if(previous_object() || !requests[line] || !requests[line][0] || !info ||
      sscanf(info, "%s : USERID : %s : %s\r\n", tmp, machine, name) != 3) {
     socket_close(line);
     map_delete(requests, line);
   return; }

   userid = name + "@" + query_ip_name(requests[line][0]);
 
   requests[line][0]->query_link()->set("userid", userid);

   socket_close(line);
   map_delete(requests, line);
 
}
 
mapping query_requests() {  return requests;  }
 
