// token.c

inherit ITEM;
inherit F_AUTOLOAD;
inherit F_SAVE;

void create()
{
	set_name("领袖信物", ({ "token" }) );
	set("unit", "个");
	set("leader_title", "掌门人");
	seteuid(getuid());
}

string short()
{
	string guild;

	if( stringp(query("short")) || !stringp(guild = query("guild_name")) )
		return ::short();
	else
		return guild + ::short();
}

string long()
{
	if( stringp(query("long")) )
		return ::long();
	else if ( stringp(query("guild_id"))) return @TEXT
这是一个已经解开封印的领袖信物，你可以用以下指令来创造属於你自己的门派
或帮会组织：

    modify <项目> <字串>    修改信物的外观、门派名称等等
    assign                  将组织领袖的位置传给别人
    dismiss                 永久解散这个组织
    
TEXT
	;
	else return @TEXT
这是一个用来让玩家建立门派、帮会时所用的领袖信物，持有这项物品的人就是
这个组织的领袖(掌门人)，领袖具有招募新成员、开除原有成员、以及更改成员
称号等权力，这项信物会自动储存，在建立一个门派之前必须先有一名巫师解除
信物石的封印(unseal)。
TEXT
	;
}

void init()
{
	if( !environment()->is_character() ) {
		message_vision("$N发出一阵耀眼的光芒，然後消失了。\n", this_object());
		destruct(this_object());
	} else {
		add_action("do_unseal", "unseal");
		add_action("do_assign", "assign");
		add_action("do_modify", "modify");
		add_action("do_dismiss", "dismiss");
	}
}

string query_autoload() { return query("guild_id"); }

string query_save_file() { return DATA_DIR + "guild/" + query("guild_id"); }

void autoload(string name)
{
	if( !restore() ) {
		if( environment() ) environment()->delete("family");
		destruct(this_object());
	}
}

int do_unseal(string arg)
{
	int i;
	string guild_id, guild_name;

	if( query("guild_id") )
		return notify_fail( query("name") + "的封印已经被解开了。\n");

	if( !wizardp(this_player(1)) )
		return notify_fail(
			"只有巫师能解除领袖信物的封印，如果你要创立一个新的门派或帮会，请\n"
			"先找一位巫师做担保人，请他(她)为你解除封印。\n");

	if(!arg) 
		return notify_fail("指令格式：unseal <门派代号> <门派名称>\n");

	if( sscanf(arg, "%s %s", guild_id, guild_name)!= 2 ) {
		set("guild_id", arg);
		if( restore() ) {
			write("Ok.\n");
			return 1;
		} else {
			delete("guild_id");
			return notify_fail("没有这个门派。\n");
		}
	}

	for(i=0; i<strlen(guild_id); i++)
		if( guild_id[i] < 'a' || guild_id[i] > 'z' )
			return notify_fail("<门派代号>必须由小写英文字母组成。\n");

	set("guild_id", guild_id);
	set("guild_name", guild_name);

	if(file_size(query_save_file() + SAVE_EXTENSION)>=0	)
		restore();
	else {
		log_file("UNSEAL", sprintf("%s [%s] by %s, %s\n",
			guild_name, guild_id, this_player(1)->query("id"), ctime(time()) ));
	}

	write("Ok.\n");
	return 1;
}

int do_assign(string arg)
{
	object ob;
	mapping family;
	string assign_msg;

	if( !arg || !objectp(ob = present(arg, environment(this_player())))
	|| !living(ob) ) 
		return notify_fail("你要将掌门人之位传给谁？\n");

	family = this_player(1)->query("family");

	if( wizardp(this_player(1)) || (
		mapp(family) && family["family_name"]==(string)query("guild_name")
		&& (string)this_player(1)->query("id")==(string)query("leader"))	) {
		// If this is a new guild, create its family.
		if( !query("leader") )
			ob->create_family(query("guild_name"));
		else {
			family = ob->query("family");
			if( !mapp(family) || (family["family_name"]!=(string)query("guild_name")) )
				return notify_fail( ob->query("name") + "并不是" + query("guild_name") + "的一份子。\n");
		}
		ob->assign_apprentice( query("leader_title"), -1 );
		set("leader", ob->query("id"));
		if( stringp(assign_msg = query("assign_msg")) )
			message_vision( assign_msg, this_player(1), ob);
		else
			message_vision(
				"\n$N将" + query("guild_name") + "的" + query("name") + "交给了$n。\n"
				"\n今後$p就是" + query("guild_name") + "的掌门人了。\n\n", this_player(1), ob);
		move(ob);
		write("Ok.\n");
		return 1;
	} else
		return notify_fail("你没有这种权力。\n");
}

int do_modify(string arg)
{
	string prop, str;

	if( !query("guild_id") ) return 0;
	
	if( !arg || sscanf(arg, "%s %s", prop, str)!=2 )
		return notify_fail("指令格式：modify <项目> <讯息>\n");
	switch(prop) {
		case "name":
		case "long":
		case "short":
		case "assign_msg":
		case "leader_title":
			set(prop, str);
			save();
			write("Ok.\n");
			break;
		default:
			write("你能修改的项目只有：name, short, long, assign_msg, leader_title。\n");
	}
	return 1;
}

int do_dismiss(string arg)
{
	if( !query("guild_id") ) return 0;

	rm(query_save_file() + SAVE_EXTENSION);
	write( query("guild_name") + "被解散了。\n");
	destruct(this_object());
	return 1;
}
