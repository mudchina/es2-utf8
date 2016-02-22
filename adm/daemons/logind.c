// logind.c

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_DBASE;

int wiz_lock_level = WIZ_LOCK_LEVEL;
string *banned_name = ({
        "你", "你", "我", "他", "她", "它", "它",
        "安尼席洛特尔",
});

private void get_id(string arg, object ob);
private void confirm_id(string yn, object ob);
object make_body(object ob);
private init_new_player(object user);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);

void create() 
{
        seteuid(getuid());
        set("channel_id", "连线精灵");
}

void logon(object ob)
{
        object *usr;
        int i, wiz_cnt, ppl_cnt, login_cnt;

        cat(WELCOME);
        UPTIME_CMD->main();

        usr = users();
        wiz_cnt = 0;
        ppl_cnt = 0;
        login_cnt = 0;
        for(i=0; i<sizeof(usr); i++) {
                if( !environment(usr[i]) ) login_cnt++;
                else if( wizardp(usr[i]) ) wiz_cnt++;
                else ppl_cnt++;
        }
        printf("目前共有 %d 位巫师、%d 位玩家在线上，以及 %d 位使用者尝试连线中。\n\n",
                wiz_cnt, ppl_cnt, login_cnt );

        write("您的英文名字：");
        input_to( (: get_id :), ob );
}

private void get_id(string arg, object ob)
{
        object ppl;


        arg = lower_case(arg);
        if( !check_legal_id(arg)) {
                write("您的英文名字：");
                input_to("get_id", ob);
                return;
        }

#ifdef MAX_USERS
        if( (string)SECURITY_D->get_status(arg)=="(player)"
        && sizeof(users()) >= MAX_USERS ) {
                ppl = find_body(arg);
        // Only allow reconnect an interactive player when MAX_USERS exceeded.
                if( !ppl || !interactive(ppl) ) {
                        write("对不起，" + MUD_NAME + 
"的使用者已经太多了，请待会再来。\n");
                        destruct(ob);
                        return;
                }
        }
#endif

//        if( wiz_level(arg) < wiz_lock_level ) {
//                write("对不起，" + MUD_NAME + "目前限制巫师等级 " + 
//WIZ_LOCK_LEVEL
//                        + " 以上的人才能连线。\n");
//                destruct(ob);
//                return;
//        }
        
        if( (string)ob->set("id", arg) != arg ) {
                write("Failed setting user name.\n");
                destruct(ob);
                return;
        }

        if( arg=="guest" ) {
                // If guest, let them create the character.
                confirm_id("Yes", ob);
                return;
        } else if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 
) {
                if( ob->restore() ) {
                        write("请输入密码：");
                        input_to("get_passwd", 1, ob);
                        return;
                }
                write("您的人物储存挡出了一些问题，请利用 guest 
人物通知巫师处理。\n");
                destruct(ob);
                return;
        }

        write("使用 " + (string)ob->query("id") + " 
这个名字将会创造一个新的人物，您确定吗(y/n)？");
        input_to("confirm_id", ob);
}

private void get_passwd(string pass, object ob)
{
        string my_pass;
        object user;

        write("\n");
        my_pass = ob->query("password");
        if( crypt(pass, my_pass) != my_pass ) {
                write("密码错误！\n");
                destruct(ob);
                return;
        }

        // Check if we are already playing.
        user = find_body(ob->query("id"));
        if (user) {
                if( user->query_temp("netdead") ) {
                        reconnect(ob, user);
                        return;
                }
                
write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
                input_to("confirm_relogin", ob, user);
                return;
        }

        if( objectp(user = make_body(ob)) ) {
                if( user->restore() ) {
                        log_file( "USAGE", sprintf("%s loggined from %s 
(%s)\n", user->query("name"),
                                query_ip_name(ob), ctime(time()) ) );
                        enter_world(ob, user);
                        return;
                } else {
                        destruct(user);
                }
        }
        write("请您重新创造这个人物。\n");
        confirm_id("y", ob);
}

private void confirm_relogin(string yn, object ob, object user)
{
        object old_link;

        if( yn=="" ) {
                
write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
                input_to("confirm_relogin", ob, user);
                return;
        }       

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write("好吧，欢迎下次再来。\n");
                destruct(ob);
                return;
        } else {
                tell_object(user, "有人从别处( " + query_ip_number(ob)
                        + " )连线取代你所控制的人物。\n");
                log_file( "USAGE", sprintf("%s replaced by %s (%s)\n", 
user->query("name"),
                        query_ip_name(ob), ctime(time()) ) );
        }

        // Kick out tho old player.
        old_link = user->query_temp("link_ob");
        if( old_link ) {
                exec(old_link, user);
                destruct(old_link);
        }

        reconnect(ob, user);    
}

private void confirm_id(string yn, object ob)
{
        if( yn=="" ) {
                write("使用这个名字将会创造一个新的人物，您确定吗(y/n)？");
                input_to("confirm_id", ob);
                return;
        }       

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write("好吧，那麽请重新输入您的英文名字：");
                input_to("get_id", ob);
                return;
        }

        write( @TEXT

请您想一个有气质，有个性，又不会太奇怪的中文名字，特别要提醒您
的是，本 mud 是一个以古中国与东方为背景的世界 ，请不要取一些不
雅或是容易造成他人困扰的名字，这个名字将代表你的人物，而且往後
将不能再更改，请务必慎重。
  ^^^^^^^^^^
(除了名字之外，本 mud 有许多取绰号、别称的设计，所以郑重建议您
 取一个比较像名字的中文名字。)

TEXT
        );
        write("您的中文名字：");
        input_to("get_name", ob);
}

private void get_name(string arg, object ob)
{
        if( !check_legal_name(arg) ) {
                write("您的中文名字：");
                input_to("get_name", ob);
                return;
        }

        printf("%O\n", ob);
        ob->set("name", arg);
        write("请设定您的密码：");
        input_to("new_password", 1, ob);
}

private void new_password(string pass, object ob)
{
        write("\n");
        if( strlen(pass)<5 ) {
                write("密码的长度至少要五个字元，请重设您的密码：");
                input_to("new_password", 1, ob);
                return;
        }
        ob->set("password", crypt(pass,0) );
        write("请再输入一次您的密码，以确认您没记错：");
        input_to("confirm_password", 1, ob);
}

private void confirm_password(string pass, object ob)
{
        string old_pass;
        write("\n");
        old_pass = ob->query("password");
        if( crypt(pass, old_pass)!=old_pass ) {
                write("您两次输入的密码并不一样，请重新设定一次密码：");
                input_to("new_password", 1, ob);
                return;
        }

        write("您的电子邮件地址：");
        input_to("get_email",  ob);
}

private void get_email(string email, object ob)
{
        object user;

        ob->set("email", email);

  // If you want do race stuff, ask player to choose one here, then you can
  // set the user's body after the question is answered. The following are
        // options for player's body, so we clone a body here.
        ob->set("body", USER_OB);
        if( !objectp(user = make_body(ob)) )
                return;

        write("您要扮演男性(m)的角色或女性(f)的角色？");
        input_to("get_gender", ob, user);
}

private void get_gender(string gender, object ob, object user)
{
        if( gender=="" ) {
                write("您要扮演男性(m)的角色或女性(f)的角色？");
                input_to("get_gender", ob, user);
                return;
        }

        if( gender[0]=='m' || gender[0]=='M' )
                user->set("gender", "男性");
        else if( gender[0]=='f' || gender[0]=='F' )
                user->set("gender", "女性" );
        else {
                write("对不起，您只能选择男性(m)或女性(f)的角色：");
                input_to("get_gender", ob, user);
                return;
        }

        log_file( "USAGE", sprintf("%s was created from %s (%s)\n", 
user->query("id"),
                query_ip_name(ob), ctime(time()) ) );
        init_new_player(user);
        enter_world(ob, user);
}

object make_body(object ob)
{
        string err;
        object user;
        int n;

        user = new(ob->query("body"));
        if(!user) {
                
write("现在可能有人正在修改使用者物件的程式，无法进行复制。\n");
                write(err+"\n");
                return 0;
        }
        seteuid(ob->query("id"));
        export_uid(user);
        export_uid(ob);
        seteuid(getuid());
        user->set("id", ob->query("id"));
        user->set_name( ob->query("name"), ({ ob->query("id")}) );
        return user;
}

private init_new_player(object user)
{
        user->set("title", "普通百姓");
        user->set("birthday", time() );
        user->set("potential", 99);

        user->set("str", 30/*10 + random(21)*/);
        user->set("cps", 30/*10 + random(21)*/);
        user->set("int", 30/*10 + random(21)*/);
        user->set("cor", 30/*10 + random(21)*/);
        user->set("con", 30/*10 + random(21)*/);
        user->set("spi", 30/*10 + random(21)*/);
        user->set("per", 30/*10 + random(21)*/);
        user->set("kar", 30/*10 + random(21)*/);
	user->set("gift_tag", 1);

        user->set("food", user->max_food_capacity());
        user->set("water", user->max_water_capacity());

        user->set("channels", ({ "chat" }) );
}

varargs void enter_world(object ob, object user, int silent)
{
        object cloth, room;
        string startroom;

        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        exec(user, ob);

        write("目前权限：" + wizhood(user) + "\n");
        user->setup();

        // In case of new player, we save them here right aftre setup 
        // compeleted.
        user->save();
        ob->save();

	// check if need allot gift
	if ( user->query("gift_tag") )
		if ( user->query("age") >= 15) {
        		user->set("str", 10 + random(21));
        		user->set("cps", 10 + random(21));
        		user->set("int", 10 + random(21));
        		user->set("cor", 10 + random(21));
        		user->set("con", 10 + random(21));
        		user->set("spi", 10 + random(21));
        		user->set("per", 10 + random(21));
        		user->set("kar", 10 + random(21));
        		user->delete("gift_tag");
			}

        cloth = new("/obj/cloth");
        cloth->move(user);
        cloth->wear();

        if( !silent ) {
                cat(MOTD);
                if( ob->query("new_mail") ) {
                        write( GRN + 
"\n杜宽告诉你：有您的信！请到驿站来一趟...\n\n" + NOR);
                        ob->set("new_mail", 0);
                }
                if( user->is_ghost() )
                        startroom = DEATH_ROOM;
                else if( !stringp(startroom = user->query("startroom")) )
                        startroom = START_ROOM;

                if( !catch(load_object(startroom)) )
                        user->move(startroom);
                else {
                        user->move(START_ROOM);
                        startroom = START_ROOM;
                        user->set("startroom", START_ROOM);
                }
                tell_room(startroom, user->query("name") + 
"连线进入这个世界。\n",
                        ({user}));
        }
        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s由%s连线进入。", user->name(), 
query_ip_name(user)) );
        UPDATE_D->check_user(user);
}

varargs void reconnect(object ob, object user, int silent)
{
        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        exec(user, ob);

        user->reconnect();
        if( !silent ) {
                tell_room(environment(user), user->query("name") + 
"重新连线回到这个世界。\n",
                ({user}));
        }
        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s由%s重新连线进入。", user->query("name"), 
query_ip_name(user)) );
        UPDATE_D->check_user(user);
}

int check_legal_id(string id)
{
        int i;

        i = strlen(id);
        
        if( (strlen(id) < 3) || (strlen(id) > 12 ) ) {
                write("对不起，你的英文名字必须是 3 到 12 个英文字母。\n");
                return 0;
        }
        while(i--)
                if( id[i]<'a' || id[i]>'z' ) {
                        write("对不起，你的英文名字只能用英文字母。\n");
                        return 0;
                }

        return 1;
}

int check_legal_name(string name)
{
        int i;

        i = strlen(name);
        
        if( (strlen(name) < 2) || (strlen(name) > 12 ) ) {
                write("对不起，你的中文名字必须是 1 到 6 个中文字。\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("对不起，你的中文名字不能用控制字元。\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("对不起，请您用「中文」取名字。\n");
                        return 0;
                }
        }
        if( member_array(name, banned_name)!=-1 ) {
                write("对不起，这种名字会造成其他人的困扰。\n");
                return 0;
        }

        return 1;
}

object find_body(string name)
{
        object ob, *body;

        if( objectp(ob = find_player(name)) )
                return ob;
        body = children(USER_OB);
        for(int i=0; i<sizeof(body); i++)
                if( clonep(body[i])
                &&      getuid(body[i]) == name ) return body[i];

        return 0;
}

int set_wizlock(int level)
{
        if( wiz_level(this_player(1)) <= level )
                return 0;
        if( geteuid(previous_object()) != ROOT_UID )
                return 0;
        wiz_lock_level = level;
        return 1;
}
 
