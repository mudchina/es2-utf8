 
//	File	:  /adm/daemons/telnetd.c
//	Creator	:  Watcher@TMI  (03/28/93)
//
//	This daemon handles all outgoing telnet socket use approval,

#include <mudlib.h>
#include <net/telnet.h>
#include <net/socket.h>
#include <uid.h>

inherit DAEMON ;
 
void load_sites();
 
string *SITES;
 
create() {  seteuid(getuid(this_object()));  load_sites();  }
 
void load_sites() {
   string *tmp, file;
   int loop;
 
   SITES = ({ });
 
   //  Read in the list of approved sites.
 
   file = read_file( APPROVED_SITES );
  
   //  Check to see if there is such a file and if it has any addresses.
 
   if(!file)  return;
 
   tmp = explode(file, "\n");

   for(loop=0; loop<sizeof(tmp); loop++)
	if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
	   continue;
	else SITES += ({ tmp[loop] });

}
 
//  Whenever a socket command is initiated, master.c's valid_socket()
//  will ask the telnet daemon to see if the action is permitted.
//  The info array passes the following information:
//	info[0]	= int fd
//	info[1] = object owner
//	info[2] = string ip_address
//	info[3] = int port
 
int telnet_permission(object caller, string func, mixed *info) {
   string eff_user, tmp1, tmp2, tmp3;
   int loop;
 
#if 0
   log_file("telnetd","Caller: " + identify(caller) + "  Func: " + identify(func) + "  Info: " + identify(info) + "\n");
#endif
 
   //	If approved sites aren't loaded yet ... load em.
 
   if(!SITES)  load_sites();
 
   //	Get calling object's Euid ...

   eff_user = geteuid(caller);
 
 
   //	If the caller is an Admin, or they are using a ROOT_UID 
   //	calling object ... approve the telnet attempt.
   //   Mobydick added the socket group and gave it access on 4-11-93.
 
  if(member_group(eff_user, "admin") || eff_user == ROOT_UID ||
	member_group(eff_user, "socket"))
	return 1;
 
 
   //	If telnet object is an approved client ... approve telnet attempt.
 
   if(caller && member_array(base_name(caller), APPROVED_TELNET) != -1)
	return 1;
 
 
   //	If no ip number is given by the request ... tentatively approve it.
 
   if(!info[2])  return 1;
 
 
   //	Check to see if requested site matches a permitted telnet site.

   for(loop=0; loop<sizeof(SITES); loop++) {
 
   if(SITES[loop] == info[2])  return 1;	// Positive direct match
 
   else if(SITES[loop] == "*.*.*.*")  return 1;	// Full wildcard match

   //	Check for pattern wildcard matching
 
   else if(sscanf(SITES[loop],"%s.*.*.*", tmp1) == 1) {
	if(sscanf(info[2], tmp1 + ".%s.%s.%s", tmp1, tmp2, tmp3) == 3)
		return 1;
   }
   else if(sscanf(SITES[loop], "%s.%s.*.*", tmp1, tmp2) == 2) {
	if(sscanf(info[2], tmp1 + "." + tmp2 + ".%s.%s", tmp1, tmp2) == 2)
		return 1;
   }
   else if(sscanf(SITES[loop], "%s.%s.%s.*", tmp1, tmp2, tmp3) == 3) {
	if(sscanf(info[2], tmp1 + "." + tmp2 + "." + tmp3 + ".%s", tmp1) == 1)
		return 1; 
   }
 
   }

return 0; }
 
