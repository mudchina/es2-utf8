
inherit ROOM;

void create()
{
   set("short", "夹道");
	set("long", @LONG
你走在后厅内院的夹道上，庄内像这样的走廊很多，你若没有地
理概念很容易迷路。长长的走道中, 纯金铸成的长灯架上挂了一排饰
丽的宫灯! 入夜之后灯火辉煌! 十分美丽!
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "south" :__DIR__"guest1",
    "east" :__DIR__"twoc",
    "west" :__DIR__"two2",

]));

	setup();
	replace_program(ROOM);
}
