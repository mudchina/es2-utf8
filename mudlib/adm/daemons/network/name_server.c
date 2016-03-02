//	File	:  /adm/daemons/network/name_server.c
//	Creator	:  Huthar@Portals|MIRE|TMI|Genocide|OD
//
//	This is the mudlib's name server daemon.

// 93-08-09 Grendel made this the auxiliary name server.
// 95-06/15 Annihilator@ES2 port this to ES2 mudlib.

#include <net/config.h>
#include <net/services.h>
#include <net/dns.h>
#include <net/macros.h>
 
mapping muds;

void error(int i,string file, string message);
void load_muds();
void load_services();

mapping query_muds()
{
   if(geteuid(previous_object()) == ROOT_UID)  return muds + ([]);
}

void create()
{
	muds = ([ "DEFAULT" : ([]) ]);
	seteuid(ROOT_UID);
	load_muds();
	load_services();
}

string get_host_name(string alias)
{
   if(!mapp(muds[alias]))
      return "";
   return muds[alias]["address"];
}

int get_mudresource(string mud, string resource)
{
   int tmp;

   if(mud == "DEFAULT" || !mapp(muds[mud]))
      return 0;
   if(resource == "DEFAULT")
      return muds[mud]["port"];

   if(muds[mud][resource])
      return muds[mud]["port"] + muds[mud][resource];
   if(muds["DEFAULT"][resource] >= 10000)
      return muds["DEFAULT"][resource] - 10000;
   tmp = muds[mud]["port"] + muds["DEFAULT"][resource];
   if(tmp == muds[mud]["port"])
      return 0;

   return tmp;
}

void load_muds()
{
   int i;
   string *line;
   string md,ad;
   int pt;

// This stuff is commented out, prior to dropping support for TCP style
// Intermud
/*
   line = explode(read_file(MUD_ADDRESSES),"\n");

   for(i = 0; i < sizeof(line); i++)
   {
      if(line[i] == "" || line[i][0] == '#')
         continue;
      if(sscanf(line[i],"%s:%s:%d",md,ad,pt) != 3)
      {
         error(i,MUD_ADDRESSES,"Syntax Error");
         continue;
      }
      if(mapp(muds[md]))
      {
         error(i,MUD_ADDRESSES,"Duplicate entry for mud: "+md);
         continue;
      }

      muds[md] = ([ "address" : ad, "port" : pt ]);
   }
*/
   return ;
}

// this is used by the dns master to get the static muds
mapping build_static_database()
{
	int i;
	string *mud_names;
	string pt, ad;
	mapping m;

	mud_names = keys(muds);
	i = sizeof(mud_names);
	m = allocate_mapping(i);
	while(i--) {
		ad = muds[mud_names[i]]["address"];
		pt = muds[mud_names[i]]["port"];

		m[mud_names[i]] = ([
			"HOSTADDRESS" : ad,
			"PORT" : sprintf("%d",pt),
			"NAME" : nntoh( mud_names[i] ),
			"TCP" : "only",
			"ALIAS" : nntoh( mud_names[i] ),
			"PORTUDP" : sprintf("%d",SRVC_PORT_UDP(pt)) ]);
	}
	return m;
}

void load_services()
{
   int i;
   string *line;
   string md,sv,tmp;
   int pt;

   line = explode(read_file(MUD_SERVICES),"\n");

   for(i = 0; i < sizeof(line); i++)
   {
      if(line[i] == "" || line[i][0] == '#')
         continue;
      if(sscanf(line[i],"%s:%s:%d",md,sv,pt) != 3)
      {
         error(i,MUD_SERVICES,"Syntax Error");
         continue;
      }
      if(!mapp(muds[md]))
      {
         error(i,MUD_SERVICES,"The mud '"+md+"' is not defined.");
         continue;
      }
      if(sv == "address" || sv == "port")
      {
         error(i,MUD_SERVICES,"The service '"+sv+"' is a reserved name.");
         continue;
      }
      if(stringp(muds[md][sv]))
      {
         error(i,MUD_SERVICES,"Duplicate service '"+sv+"' defined.");
         continue;
      }
      if(sscanf(line[i],"%*s:%*s:%s",tmp) && tmp[0] != '-' && tmp[0] != '+')
         pt = ((md != "DEFAULT") ? pt - muds[md]["port"] : pt + 10000);

      muds[md] += ([ sv : pt ]);
   }
}

void error(int line, string file, string message) 
{
   write("ERROR: Line "+line+" of "+file+": ");
   write(message+"\n");
}
