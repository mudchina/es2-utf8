//      /adm/daemon/mail_serv.c
//      from the Nightmare Mudlib
//      the intermud mail server compatible with Huthar's mailer and
//      the IIPS by Descartes of Borg
//      originally written by Huthar
//      some modifications by Blackthorn@Genocide and Truilkan@Basis
//      rewritten by Descartes of Borg for IIPS

#include <net/daemons.h>
#include <daemons.h>
#include <uid.h>
#include <post.h>

#define log(x) log_file("MS", x)
#define MS_SAVE "mail-queue"
#define FLUSH_TIME 86400
#define AGE_TIME 604800
#define EOF "%EOF%"
#define EOT "%EOT%"
 
static string upd;
static mapping new_mail_queue, sockets;
static string receiver, from, to, subject, message,cc;
static int date;
static string mud;
static mixed mqi;
static mapping mud_groups;
static mixed outgoing;
 
mixed mail_queue;
int date_last_flushed;
 
void process_message(int fd);
void flush_mail_queue();
void age_queue();
void bad_port(string mud, string from, string message);
 
void reset() {
    if( (time()-date_last_flushed) > FLUSH_TIME) {
        mqi = keys(mail_queue);
        flush_mail_queue();
        date_last_flushed = time();
    }
    age_queue();
}

void create() {
    seteuid(getuid());
    mail_queue = ([]);
    sockets = ([]);
    mqi = ({});
    restore_object(DIR_POSTAL+"/"+MS_SAVE);
    mud_groups = (mapping)POSTAL_D->query_mud_groups();
    mqi = keys(mail_queue);
    flush_mail_queue();
}
 
string convert_name(string nom, string lmud) {
    string tmp, tmpaddr;

    if(sscanf(nom, "%s@%s", tmp, tmpaddr) != 2) {
        tmp = nom;
        tmpaddr = lmud;
    }
    if(lower_case(tmpaddr) != lower_case(mud_name()))
      return tmp+"@"+tmpaddr;
    return tmp;
}
 
void remote_mail(string who, string lmud, mapping borg) {
    string *tmp;
    int i, max;

    if(geteuid(previous_object()) != ROOT_UID) {
        log_file("illegal", "Illegal attempt to access mail server: "+
          ctime(time())+"\n");
        return;
    }
    if(!borg["message"]) borg["message"] = "\n";
    for(i=0, max = sizeof(tmp=explode(borg["message"], "\n")); i<max; i++) {
        if(tmp[i] == EOF) tmp[i] = EOF+".";
        else if(tmp[i] == EOT) tmp[i] == EOT+".";
    }
    if(!tmp) tmp = ({});
    borg["message"] = implode(tmp, "\n");
    if(!mail_queue[lmud]) mail_queue[lmud] = ({});
    mail_queue[lmud] += ({ ([ "recipient": who, "to": borg["to"],
      "cc": borg["cc"], "from": borg["from"], "subject": borg["subject"],
      "date": borg["date"], "message": borg["message"] ]) });
    save_object(DIR_POSTAL+"/"+MS_SAVE);
    mqi += ({ lmud });
}
 
void bad_port(string mud, string from, string msg) {
    string to_ob;

    to_ob = "Failed to deliver mail to "+from+"@"+mud+".\n"+
      "Either the mud does not exist or a wrong port number is in\n"+
      mud_name()+"'s files.  If the mud should exist and you know\n"+
      "it to be part of the intermud system, mail the admins here.\n"+
      "Text of your original message as follows:\n\n";
    POSTAL_D->post_mail( ([ "from": "postal_daemon", "to": ({ from }),
      "cc": ({}), "message": to_ob+msg, "date":time(),
      "subject": "Invalid remote address" ]) );
    map_delete(mail_queue, mud);
}
 
void remove() { destruct(this_object()); }
 
void set_mqi(mixed m) { mqi = m; }

string *query_mqi() { return mqi; }
 
mapping query_mail_queue() { return mail_queue; }

void set_mail_queue(mixed a) { mail_queue = a; }
 
void clear_mail_queue() {
    mail_queue = ([]);
    save_object(DIR_POSTAL+"/"+MS_SAVE);
}
 
void age_queue() {
    int i, j;
    string *key;
    mixed tmp;

    i = sizeof(key = keys(mail_queue));
    while(i--) {
        tmp = mail_queue[key[i]];
        for(j=0; j<sizeof(tmp); j++) {
            if( (time()-tmp[j]["date"]) > AGE_TIME) {
                log("Aging mail from "+tmp[j]["from"]+" dated "+tmp[j]["date"]+
                  "\n");
                exclude_array(tmp, j);
            }
        }
    }
}
 
void close_callback(int id) { map_delete(sockets, id); }

void service_request(int id) { sockets[id] = (["msg": "" ]); }

void read_callback(int id, string data) {
    if(data == (EOT+"\n")) {
        sockets[id]["msg"] += data;
        process_message(id);
    }
    else sockets[id]["msg"] += data;
}
 
void process_message(int id) {
    string *local, *bad_people;
    mixed tmp, tmp2;
    string *totmp, *cctmp;
    int i, j;
    string bad_list, a, b;

    sscanf(sockets[id]["msg"], "%s\n%s", mud, tmp);
    sockets[id]["msg"] = tmp;
    tmp = explode(sockets[id]["msg"], EOF);
    tmp2 = allocate(sizeof(tmp=tmp[0..sizeof(tmp)-2]));
    for(i=0; i<sizeof(tmp); i++) tmp2[i] = explode(tmp[i], "\n");
    for(i=0; i<sizeof(tmp2); i++)  {
        receiver = convert_name(tmp2[i][0], lower_case(mud_name()));
        totmp = explode(tmp2[i][1], " ");
        for(j=0; j<sizeof(totmp); j++) totmp[j] = convert_name(totmp[j], mud);
        cctmp = explode(tmp2[i][2], " ");
        if(cctmp[0]) {
            for(j=0; j<sizeof(cctmp); j++) cctmp[j]=convert_name(cctmp[j],mud);
        }
        else cctmp = ({});
        from = convert_name(tmp2[i][3], mud);
        subject = tmp2[i][4];
        sscanf(tmp2[i][5], "%d", date);
        message = implode(tmp2[i][6..sizeof(tmp2[i])-1], "\n");
        for(j=0, local = ({}), bad_people = ({}); j<sizeof(totmp); j++) {
            if(sscanf(totmp[j], "%s@%s", a, b) == 2) continue;
            if(user_exists(totmp[j])) local += ({ totmp[j] });
            else if(mud_groups[totmp[j]]) local += mud_groups[totmp[j]];
            else bad_people += ({ totmp[j] });
        }
        for(j=0; j<sizeof(cctmp); j++) {
            if(sscanf(cctmp[j], "%s@%s", a, b) == 2) continue;
            if(user_exists(cctmp[j])) local += ({ cctmp[j] });
            else if(mud_groups[cctmp[j]]) local += mud_groups[cctmp[j]];
            else bad_people += ({ cctmp[j] });
        }
        POSTAL_D->add_post(local,
          ([ "to":totmp, "cc":cctmp, "from":from, "subject":subject, "date":date, "message":message ])
        );
        POSTAL_D->notify_online(local, from, subject);
        POSTAL_D->flush_files();
        if(sizeof(bad_people) &&
          (j=sizeof(bad_people = uniq_array(bad_people)))) {
            bad_list = "";
            while(j--) bad_list += bad_people[j]+" ";
            sscanf(from, "%s@%s", a, b);
            remote_mail(a, b, ([ "from": "postal_daemon", "to": ({from}),
              "subject": "Invalid recepient", "cc": ({}), "date":time(),
              "message": "The following recipients cannot be found on "+
              mud_name()+":\n"+bad_list+"\n\nOriginal mail text follows:\n\n"+
              message ]));
        }
    }
}
 
void flush_mail_queue() {
    string *muds;
    string address, port;
    int id;

    if(!sizeof(mqi)) return;
    outgoing = mail_queue[mqi[0]];
    if( (id = (int)INETD->open_service(mqi[0], "mail")) < 0) {
        log("flush_mail_queue: open service: "+socket_error(id)+"\n");
        mqi -= ({ mqi[0] });
        flush_mail_queue();
    }
}
 
void service_callback(int id) {
    int i;
 
    INETD->write_socket(id, lower_case(mud_name()) + "\n");
    for(i=0; i<sizeof(outgoing); i++) {
        INETD->write_socket(id, outgoing[i]["recipient"] + "\n");
        INETD->write_socket(id, implode(outgoing[i]["to"], " ") + "\n");
        INETD->write_socket(id, implode(outgoing[i]["cc"], " ") + "\n");
        INETD->write_socket(id, outgoing[i]["from"] + "\n");
        INETD->write_socket(id, outgoing[i]["subject"] + "\n");
        INETD->write_socket(id, outgoing[i]["date"] + "\n");
        INETD->write_socket(id, outgoing[i]["message"] + "\n");
        INETD->write_socket(id, EOF + "\n");
    }
    INETD->write_socket(id, EOT + "\n");
    INETD->close_socket(id);
    map_delete(mail_queue, mqi[0]);
    mqi -= ({ mqi[0] });
    save_object(DIR_POSTAL+"/" + MS_SAVE);
    call_out("flush_mail_queue", 60);
}
