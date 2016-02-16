// Room: /d/oldpine/keep2.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "老松寨");
	set("long", @LONG
这里应该是老松寨了，虽然围绕著你的墙都是木头搭成的，但是仔
细一看，在许多险要的位置都放了不少沙包石堆，后面显然是埋伏人手
的好地方，如果有人贸然从大门口攻进来，肯定会吃大亏的，大寨的门
在你的西边，东边越过一排木桩之后就是大厅。
LONG
	);
	
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"keep1",
		"east" : __DIR__"keep3",
	]));
	set("objects", ([
		__DIR__"npc/bandit_guard" : 2,
		__DIR__"npc/bandit_leader" : 1
	]) );

	setup();
}

int valid_leave(object me, string exit)
{
	int i;
	object ob;

	if( exit != "east"
	||	!query("exits/west") )
		return 1;

	message("vision",
		HIY "你听到你身后有几个声音大叫：把门关上！把门关上！一个也不许\让他们溜走！\n" NOR
			"接著「轰」地一声，通往外面的大门已经被一块大石堵死了。\n",
		this_object() );
	delete("exits/west");
	if( ob = find_object(__DIR__"keep1") )
		ob->delete("exits/east");

	i = 5;
	while(i--) {
		ob = new(__DIR__"npc/bandit_guard");
		ob->move(this_object());
		ob->kill_ob(me);
	}
	return 1;
}

void reset()
{
	object ob;

	::reset();
	set("exits/west", __DIR__"keep1" );
	if( ob = find_object(__DIR__"keep1") )
		ob->set("exits/east", __FILE__);
	
}

void pipe_notify()
{
	object ob;

	message("vision",
		"你听到一阵轧轧的轮盘绞动声，堵住门口的大石慢慢地被移开了。\n",
		this_object() );
	set("exits/west", __DIR__"keep1" );
	if( ob = find_object(__DIR__"keep1") )
		ob->set("exits/east", __FILE__);
}
