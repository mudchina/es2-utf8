// Room: /d/wiz/courthouse.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "法院");
	set("long", @LONG
这里是东方故事的巫师审问机器人的法院，你一定是被人检举或是
行为太像机器人，才会来到这里，如果你答不出审判官的三个问题，会
被做上记号，超过三次的人将会被处以极刑，好好回答吧。
LONG
	);
	set("no_fight", 1);
	set("no_magic", 1);
	set("no_spells", 1);
	set("objects", ([
		__DIR__"npc/judge":1 ]) );

	setup();
}

void init()
{
	add_action("re_route_cmd","",1);
}

int re_route_cmd(string str)
{
        string cmd;
        int i;
        string *invalid_cmds;
        cmd = query_verb();
	invalid_cmds = ({"enforce", "meditate", "practice", "study", "drop",
                         "exercise", "learn", "scribe", "conjure", "enchant",
                         "exert", "perform", "respirate"
                       });
        i = member_array(cmd, invalid_cmds);
        if (i == -1) return 0;
        else write("到了法院你还练啥功啊, 搞不清楚状况哦。\n");
        return 1;
}

void test_me(object me)
{
	me->set_temp("old_startroom", me->query("startroom"));
	me->set("startroom", __FILE__);
	me->set_temp("last_location", base_name(environment(me)));
	message_vision("忽然一阵闪光罩住了$N。\n", me);
	me->move(this_object());
}
