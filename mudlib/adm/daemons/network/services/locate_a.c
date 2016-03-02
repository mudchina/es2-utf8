//      /adm/daemons/network/dns_aux/locate_a.c
//      from the TMI-2 Mudlib
//      the locate_a for the UDP locate function
//      created by Descartes of Borg 931017

#include <net/macros.h>

inherit F_CLEAN_UP;

void incoming_request(mapping info) {
    object who;

    if(!info["NAME"] || !info["PORTUDP"]) return;
    if(!info["ASKWIZ"] || !(who = find_player(lower_case(info["ASKWIZ"]))))
      return;
    switch(info["LOCATE"]) {
        case "NO": return;
        case "YES":
          message("info", sprintf("LOCATE:  %s was just located on %s.\n", 
            capitalize(info["TARGET"]), nntoh(info["NAME"])), who);
          break;
        default: /* log bad answers here if you like */
    }
    return;
}
