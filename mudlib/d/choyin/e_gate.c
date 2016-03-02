// Room: /d/choyin/e_gate.c

inherit ROOM;

void create()
{
	set("short", "东城门");
	set("long", @LONG
    这里乔阴县城的东门，一座高大的石牌楼上面刻著「北门」两个大
字，一条土路青郁郁地通往南边的山上，石牌楼旁蹲著一只铁狮. 与南
北两城门相比, 北门这一带显得比较冷清，偶见几个采药, 砍柴之人由
此出入。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"e_street1",
  "east" : __DIR__"solidpath1",
]));
        set("objects",([
          __DIR__"npc/cityguard":2,
          __DIR__"npc/ghost":1,
                      ]) );
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
