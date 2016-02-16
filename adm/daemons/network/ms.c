/*
 * Intermud mail server, used by Huthar's mailer daemon
 * Original author: Huthar
 * Rewritten to conform to new socket efun specs,  Blackthorn (10/31/92)
 * Small patches for TMI-2 mudlib, Buddha (11/6/92)
 *
 * Cleaned up 930413 by Zak - enhanced to use new mapping format for mail.
 * Zak, 930604	fixed up writing to remote mud, auto-format our mud
 *		name into one w/o spaces, etc.
 * Zak, 930606	noted a potential security hole. (find the `XXX'
 *		comment referring to ``enable for debugging only'')
 * Grendel, 930904  Fixed a bug in mailing to remote groups
 */
 
#include <config.h>
#include <mailer.h>
#include <daemons.h>
#include <net/daemons.h>
#include <uid.h>
 
#define log(x)		log_file("MS", x)
#define MS_SAVE		"mail-queue"
#define FLUSH_TIME	86400
#define AGE_TIME	604800
#define EOF		"%EOF%"
#define EOT		"%EOT%"
 
static mapping	sockets;
static mixed	mqi, outgoing;
static string	mname;
 
mixed mail_queue;
int date_last_flushed;
 
void flush_mail_queue();
void dump_mailq();
 

void
create()
{
    seteuid(ROOT_UID);
    mail_queue = ([ ]);
    sockets = ([ ]);
    mqi = ({ });
    restore_object(MAILDIR + MS_SAVE);
    mqi = keys(mail_queue);
    mname = lower_case(replace_string(THIS_MUD, " ", "."));
    flush_mail_queue();
} // create
 

string
convert_name(string lname, string lmud)
{
    string tmp, tmpaddr;

    if (!lname)
	return "_unknown_@" + mname;
//   if (sscanf(lname, "%s@%s", tmp, tmpaddr)==0) return lname;
    if (sscanf(lname, "%s@%s", tmp, tmpaddr) != 2)
    {
	tmp = lname;
	tmpaddr = lmud;
    }
    if (!tmp || tmp == "")
	tmp = "_unknown_";
    if (!tmpaddr || tmpaddr == "")
	tmpaddr = mname;

    if (tmpaddr != mname)
	return tmp + "@" + tmpaddr;
    return tmp;
} // convert_name
 

void
remote_mail(string own, string mud, mapping outmsg)
{
    string *tmp;

    if (file_name(previous_object()) != MAILER_D)
	return;

//printf("remote mail to: %s@%s, subj: %s\n", own, mud, outmsg["To"]);
    if (! outmsg["message"])
        outmsg["message"] = "\n";
    else
	outmsg["message"] += "\n";

    outmsg["message"] = replace_string( outmsg["message"],
				EOF + "\n", EOF + ".\n" );
    outmsg["message"] = replace_string( outmsg["message"],
				EOT + "\n", EOT + ".\n" );
    if (!mail_queue[mud])
	mail_queue[mud] = ({ });

    outmsg["recipient"] = own;
// printf("before: mq[mud] %s\n", dump_variable(mail_queue[mud]));
    mail_queue[mud] += ({ copy(outmsg) });
// printf("after: mq[mud] %s\n", dump_variable(mail_queue[mud]));
// printf("mud is %s\n", mud);
    save_object(MAILDIR + MS_SAVE);
    mqi += ({ mud });
} // remote_mail


void
dump_mailq()
{
    mixed *mk;
    int i, j;

    mk = keys(mail_queue);
    i = sizeof(mk);
    while (i--)
    {
	printf("Mud: %s\n", mk[i]);
	j = sizeof(mail_queue[mk[i]]);
	printf("%d: %s\n\t%s\n", i, dump_variable(mk[i]),
	    dump_variable(mail_queue[mk[i]]));
    }
} // dump_mailq


	// ZAKNOTE: what uses this???
void
bad_port(string lmud, string lfrom, string msg)
{
    object ob;

    ob = find_player(lfrom);
    if (!ob)
	return;

    tell_object(ob,
	"The mud " + lmud + " doesn't exist or has a bad port address.\n" +
	"If the mud should exist, notify your local admins.\n");
    tell_object(ob,
	"Saving letter in: " + TMP_DIR + "/" + lfrom + ".dead.letter\n");
    write_file(TMP_DIR + "/" + lfrom + ".dead.letter", msg);
    mail_queue[lmud] = 0;
} // bad_port

 
void
remove()
{
    destruct(this_object()); 
} // remove
 

#if 1		// XXX: enable for debugging only - Zak
void	set_mqi(mixed m)	{ mqi = m; }
string *query_mqi()		{ return mqi; }

void	set_mail_queue(mixed a)	{ mail_queue = a; }
mapping	query_mail_queue()	{ return mail_queue; }
 
void
clear_mail_queue() 
{
    mail_queue = ([ ]);
    save_object(MAILDIR + MS_SAVE);
} // clear_mail_queue
#endif

 
void
age_queue()
{
    int		i, j;
    string	*key;
    mixed	tmp;

    key = keys(mail_queue);

    i = sizeof(key);
    while (i--)
    {
	tmp = mail_queue[key[i]];
	j = sizeof(tmp);
	while (j--)
	{
	    if (time() - tmp[j]["date"] > AGE_TIME)
	    {
		log("Aging mail from: " +
			tmp[j]["from"] + ", dated: " + tmp[j]["date"] + "\n");
// ZAKNOTE: this is effectively a null statement... why???
//		exclude_array(tmp, j);
	    }
	}
    }
} // age_queue


void
reset()
{
    if ((time() - date_last_flushed) > FLUSH_TIME)
    {
	mqi = keys(mail_queue);
	flush_mail_queue();
	date_last_flushed = time();
    }
    age_queue();
} // reset
 

void
close_callback(int id)
{
    map_delete(sockets, id);
    return;
} // close_callback

 
void
service_request(int id)
{
    sockets[id] = ([ "msg" : "" ]);
} // service_request
 

void
process_message(int id)
{
    mapping	inmsg;
    mixed	tmp, tmp2;
    int		i, j, res, max;
    string	receiver, mud, grp;

    sscanf(sockets[id]["msg"], "%s\n%s", mud, tmp);
    sockets[id]["msg"] = tmp;

    tmp = explode(sockets[id]["msg"], EOF);
    tmp = tmp[0..sizeof(tmp)-2];
    tmp2 = allocate(sizeof(tmp));
    inmsg = ([ ]);

    max = sizeof(tmp);
    for (i = 0; i < max; i++) 
    {
	tmp2[i] = explode(tmp[i], "\n");
    }
    max = sizeof(tmp2);
    for (i = 0; i < max; i++)
    {
	receiver = convert_name(tmp2[i][0], mname);
	inmsg["to"] = explode(tmp2[i][1], " ");
	j = sizeof(inmsg["to"]);
	while (j--)
	    inmsg["to"][j] = convert_name(inmsg["to"][j], mud);
	inmsg["cc"] = explode(tmp2[i][2], " ");
	if (inmsg["cc"][0])
	{
	    j = sizeof(inmsg["cc"]);
	    while (j--)
		inmsg["cc"][j] = convert_name(inmsg["cc"][j], mud);
	}
	else
	    inmsg["cc"] = ({ });
	inmsg["from"] = convert_name(tmp2[i][3], mud);
	inmsg["subject"] = tmp2[i][4];
	sscanf(tmp2[i][5], "%d", inmsg["date"]);
	inmsg["message"] = implode(tmp2[i][6..sizeof(tmp2[i]) - 1], "\n");
	res = 0;
	if(sscanf(receiver, "(%s)", grp))	 // do remote group mail
	{
	    string grparr;
	    grparr = ((mapping)GROUP_OB->query_groups())[grp];
	    j = sizeof(grparr);
	    while(j--)
	    {
		res += (int)MAILER_D->add_message(grparr[j], inmsg);
	    }
	}
	else
	    res = (int)MAILER_D->add_message(receiver, inmsg);
	if (!res)
	{
	    MAILER_D->add_message(inmsg["from"], ([
		    "to" : ({ inmsg["from"] }),
		    "cc" : ({ }),
		    "from" : "MS@" + mname,
		    "subject" : "`" + capitalize(receiver)
			    + "' does not exists at this site. (MAIL BOUNCE)",
		    "date": time(),
		    "message" : "BODY OF MESSAGE FOLLOWS:\n\n"
			    + inmsg["message"]
	    ]));
			
			// XXX: rework the line below - it's ugly... -Zak
	    if (sizeof(explode(inmsg["from"], "@")) == 1)
	    {
		MAILER_D->biff(inmsg["from"], "MS", capitalize(receiver) +
			" does not at exist at this site. (MAIL BOUNCE)");
		MAILER_D->flush_files();
	    }
	    else
		call_out("flush_mail_queue", 30);
	    return;
	}
	MAILER_D->biff(receiver, inmsg["from"], inmsg["subject"]);
	MAILER_D->flush_files();
    } // for
} // process_message


void
read_callback(int id, string data)
{
    if (data == (EOT + "\n"))
    {
	sockets[id]["msg"] += data;
	process_message(id);
	return;
    }
    sockets[id]["msg"] += data;
} // read_callback
 
 
void
flush_mail_queue()
{
    string *muds, address, port;
    string tmp;
    int id;

    if (!sizeof(mqi))
	return;

    outgoing = mail_queue[mqi[0]];
    id = INETD->open_service(mqi[0], "mail");
    if (id < 0)
    {
	log("flush_mail_queue: open_service: " + socket_error(id) + "\n");
	mqi -= ({ mqi[0] });
	flush_mail_queue();
    }
    // we need some sort of time out here
} // flush_mail_queue

 
void
service_callback(int id)
{
    int i, max;
    string str;
    string to, cc;

    INETD->write_socket(id, mname + "\n");
    max = sizeof(outgoing);
    for (i = 0; i < max; i++)
    {
	to = pointerp(outgoing[i]["to"]) ? implode(outgoing[i]["to"], " ")
					  : "";
	cc = pointerp(outgoing[i]["cc"]) ? implode(outgoing[i]["cc"], " ")
					  : "";
	INETD->write_socket(id, sprintf("%s\n%s\n%s\n%s\n%s\n%d\n",
					outgoing[i]["recipient"], to, cc,
					outgoing[i]["from"],
					outgoing[i]["subject"],
					outgoing[i]["date"]));
	INETD->write_socket(id, sprintf("%s\n%s\n", outgoing[i]["message"],
					EOF));
    }
    INETD->write_socket(id, EOT + "\n");
    INETD->close_socket(id);
    map_delete(mail_queue, mqi[0]);
    mqi -= ({ mqi[0] });
    save_object(MAILDIR + MS_SAVE);
    call_out("flush_mail_queue", 60);
} // service_callback
