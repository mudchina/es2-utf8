/*
//
//  File    :  /adm/daemons/network/netmail.c
//  Author  :  Inspiral@Tabor
//  Created :  93-12-22
//  Purpose :  To facilitate proper communication between the mailer daemon
//                     and the dns system.
//
//
//  REVISION HISTORY
//  93-12-23   - Added support to mailer daemon.
//  93-12-24   - Added support for data_netmail_file() simul_efun
//
*/
 
#include <net/macros.h>
#include <mailer.h>
#include <net/dns.h>
 
 
#define SAVE_FILE(x)    ( data_netmail_file( htonn( x ) ) )
#define init_queue()    ( out_queue = ({  }) )
 
 

#define WHO find_player( "inspiral" )
#define TELL(x) if( WHO ) tell_object( WHO,"NETMAIL: " + x + "\n" )
 
mixed * out_queue;
 
mapping check_for_mail( string mudname ) {
  init_queue();
  
  if( !file_exists( SAVE_FILE( mudname ) + SAVE_EXTENSION ) )
    return 0;
  
  if( !restore_object( SAVE_FILE( mudname ) ) ) {
    log_file( "netmail", "Could not restore " + SAVE_FILE( mudname ) +
      SAVE_EXTENSION + "\n" );
    return 0;
  }
  
  if( !out_queue )
    init_queue();
  
  if( sizeof( out_queue ) )
    return out_queue[0];
  
  return 0;
}
 
int pop_mud( string mudname ) {
  init_queue();
  
  if( !file_exists( SAVE_FILE( mudname ) + SAVE_EXTENSION ) )
    return 0;
  
  if( !restore_object( SAVE_FILE( mudname ) ) ) {
    log_file( "mail_q", "Could not restore " + SAVE_FILE( mudname ) +
      SAVE_EXTENSION + "\n" );
    return 0;
  }
  
  if( !out_queue )
    init_queue();
  
  out_queue = exclude_array( out_queue, 0 );

  if( !sizeof( out_queue ) ) 
     rm( SAVE_FILE( mudname ) + SAVE_EXTENSION );
  else
     save_object( SAVE_FILE( mudname ) );
  return 1;
}
 
int push_mail( mapping outmsg ) {
  mixed *list;
  int i;
  
  outmsg["SUBJECT"] = outmsg["subject"];
  outmsg["CC"] = outmsg["cc"];
  outmsg["DATE"] = ( outmsg["date"] );
  outmsg["MSG"] = outmsg["message"];
  outmsg["WIZFROM"] = outmsg["from"] + "@" + Mud_name();
  outmsg["WIZTO"] = outmsg["to"];
  
  // Used only for housekeeping on our end.
  outmsg["TIME"] = time();
 
  map_delete( outmsg, "subject" );
  map_delete( outmsg, "cc" );
  map_delete( outmsg, "to" );
  map_delete( outmsg, "from" );
  map_delete( outmsg, "date" );
  map_delete( outmsg, "message" );
  
  
// from, to, subject, msg, cc, date
// First, make sure CC and WIZTO have proper format.
  list = outmsg["WIZTO"];
  
  i = sizeof( list );
  while( i-- ) {
    if( strsrch( list[i], "@" ) < 0 )
      list[i] += "@" + Mud_name();
  }
  
  if( !pointerp( list ) ) list = ({ list });
 
  outmsg["WIZTO"] = list;
  list = outmsg["CC"];
  
  i = sizeof( list );
  while( i-- ) {
    if( strsrch( list[i], "@" ) < 0 )
      list[i] += "@" + Mud_name();
  }
  
  if( !pointerp( list ) ) list = ({ list });
 
  outmsg["CC"] = list;
  
// now, we strip duplicates, and compile a list of muds to send to.
  list = uniq_array( outmsg["WIZTO"] + outmsg["CC"] );
  outmsg["CC"] = implode( outmsg["CC"], "," );
  
  if( outmsg["CC"] == "" ) 
        outmsg["CC"] = 0;
 
  if( pointerp( outmsg["WIZTO"] ) )
      outmsg["WIZTO"] = implode( outmsg["WIZTO"], "," );
 
  i = sizeof( list );
  
  while( i-- ) {
   if( !stringp( list[i] ) )
          list[i] = "";
    sscanf( list[i], "%*s@%s", list[i] );
  }
  
  list = uniq_array( list );
  list -= ({ Mud_name() });
  list -= ({ mud_nname() });
  list -= ({ "" });
  
  i = sizeof( list );
  
  while( i-- ) {
    init_queue();
    
        if( !SAVE_FILE( list[i] ) ) continue;
    if( !restore_object( SAVE_FILE( list[i] ) ) ) {
      log_file( "netmail", "Could not restore " + SAVE_FILE( list[i] ) +
        SAVE_EXTENSION + "\n" );
    }
    
    if( !out_queue ) init_queue();
    
    out_queue += ({ outmsg });
    save_object( SAVE_FILE( list[i] ) );
    TELL( "Saved to " + list[i] + ".db" );
    MAIL_Q -> check_for_mail( list[i], 3 );
  }
  
  return 1;
}
 
int incoming_mail( mapping info ) {
  // Convert intermud format to our mailer's format.
  if( info["CC"] && info["CC"] != "" )
    info[ "cc" ] = info["CC"];
  else info[ "cc" ] = ({ });
 
  if( !info["WIZTO"] || info["WIZTO"] == "" )
        return 0;
 
   info[ "to" ] = explode( info["WIZTO"], "," );
  if( info["CC"] )
     info["cc"] = explode( info["CC"], "," );
  info[ "from" ] = info["WIZFROM"];
   info[ "date" ] = to_int( info[ "DATE" ] );
  info[ "subject" ] = info[ "SUBJECT" ];
  info[ "message" ] = info[ "MSG" ];
  
  map_delete( info, "WIZTO" );
  map_delete( info, "CC" );
  map_delete( info, "DATE" );
  map_delete( info, "SUBJECT" );
   map_delete( info, "HOSTADDRESS" );
   map_delete( info, "ENDMSG" );
  map_delete( info, "MSG" );
  map_delete( info, "WIZFROM" );
  map_delete( info, "ALIAS" );
  map_delete( info, "NAME" );
  map_delete( info, "PORTUDP" );
 
  MAILBOX_D -> send_mail( info );
  return 1;
}
 
/* EOF */
