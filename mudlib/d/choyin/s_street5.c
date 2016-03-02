// Room: /d/choyin/s_street5.c

inherit ROOM;

void create()
{
	set("short", "承安街");
	set("long", @LONG
这里是乔阴县城南的承安街，往东可以通往热闹的南门广场，西边
的路口则是通往县府衙门的昌平街，街道北边是一些贩卖日常用具的商
店，南边则是一块空地，从这里可以看到南边的城墙。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"crossroad",
		"east" : __DIR__"s_street4",
]));
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
