// Room: /d/choyin/s_street4.c

inherit ROOM;

void create()
{
	set("short", "承安街");
	set("long", @LONG
这里是乔阴县城城南的承安街，街道十分宽敞，南北两边都是一些
贩卖南北货、日用品的商店，这里虽然正当乔阴县人车来往最频繁的要
冲，可是却没有福林大街热闹，往东走便是南门广场，往西则是和昌平
街的交叉路口。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"s_street5",
		"east" : __DIR__"s_street1",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
