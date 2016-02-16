// expell.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object ob;
	string *skname;
	mapping skills;
	int i;

	if( !arg || !ob = present(arg, environment(me)) )
		return notify_fail("你要将谁逐出师门？\n");

	if( !ob->is_character() )
		return notify_fail("你要开革「谁」？\n");

	if( !userp(ob) )
		return notify_fail("你只能开革玩家所扮演的人物。\n");

	if( me->query("family/privs")==-1
	&&	(string)me->query("family/family_name")==(string)ob->query("family/family_name") ) {
		message_vision("\n$N对著$n说道：从今天起，你再也不是我"
			+ me->query("family/family_name") + "的弟子了，你走吧！\n\n",
			me, ob);
		tell_object(ob, "\n你被" + me->query("family/title") + "开革出师门了！\n\n");
	} else if( ob->is_apprentice_of(me) ) {
		message_vision("\n$N对著$n说道：从今天起，你我师徒恩断情绝，你走吧！\n\n",
			me, ob);
		tell_object(ob, "\n你被师父开革出师门了！\n\n");
	} else
		return notify_fail("这个人不是你的弟子。\n");

	ob->delete("family");
	ob->delete("title");
	ob->set("score", 0);
	skills = ob->query_skills();

	if( mapp(skills) ) {
		skname = keys(skills);
		for(i=0; i<sizeof(skname); i++)
			skills[skname[i]] /= 2;
	}

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : expell <某人>
 
这个指令可以让你开除不成才的弟子，被开除的弟子所有技能都会降到原来
的一半，而且综合评价一项会变成零，这对於一个人物而言是一个「比死还
严重」的打击，请你在开除一名弟子之前务必审慎考虑。
 
HELP
	);
	return 1;
}
