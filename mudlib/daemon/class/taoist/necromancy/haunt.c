// haunt.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_scribe_haunt(string arg);
int do_haunt (string target, object who);

int scribe(object me, object sheet, string arg)
{
	if( me->is_fighting() ) return notify_fail("你正在战斗中！\n");

        if( (int)me->query("mana") < 20 ) return
notify_fail("你的法力不够了！\n");

        if( !arg ) return notify_fail("你要在这张符上写谁的名字？\n");

        sheet->set_name(YEL "僵尸追魂符" NOR, ({/* "haunting sheet",*/ "sheet"}));
/*        sheet->set("attach_func", (: call_other, __FILE__, "do_haunt", arg :
);*/
	// added by lingr on July 21th, -- 3 lines
	sheet->set("func_path", __FILE__);
	sheet->set("func_name", "do_scribe_haunt");
	sheet->set("func_arg", arg + " zombie");
	
        me->add("mana", -20);
        me->receive_damage("sen", 10);

        return 1;
}

// 函数 do_scribe_haunt（）
// convert arg to parameter which do_haunt can use
// added by lingr on July 21th.
int do_scribe_haunt(string arg)
{
	string target, swho;
	object who;

        if( !arg || sscanf(arg, "%s %s", target, swho) != 2 )
		return notify_fail("你给的参数不正确\n");

	if ( !objectp(	who = present(swho, environment(this_player())) ) )
		return notify_fail ("你往哪儿贴？\n");

	return do_haunt(target, who);
}
	
int do_haunt(string target, object who)
{
        object dest;

        if( !who->is_zombie() )
                return notify_fail(YEL "僵尸追魂符" NOR
"只能用在僵尸身上。\n");

        if( !who->query("possessed") )
                return notify_fail("你必须先用法力镇住" + who->name() +
"才能使用这道符。\n");

        dest = present(target, environment(who));
        if( !dest ) dest = find_player(target);
        if( !dest ) dest = find_living(target);
        if( objectp(dest) ) {
                who->kill_ob(dest);
                who->set_leader(dest);
                message_vision("$N眼睛忽然睁开，喃喃地说道：" RED
"杀....死....$n....\n" NOR,
                        who, dest);
                if( environment(dest)==environment(who) ) {
                        dest->fight_ob(who);
		who->set("end_tag", 1);
                }
        } else {
                message_vision("$N眼睛忽然睁开，喃喃地说道：" RED
"杀....杀....杀....\n" NOR,
                        who);
                if( this_player() ) {
                        who->kill_ob(this_player());
                        who->set_leader(this_player());
                        this_player()->fight_ob(who);
                }
        }
        return 1;
}

