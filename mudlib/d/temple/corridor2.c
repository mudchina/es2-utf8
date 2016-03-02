// Room: /u/k/karrimor/temple/corridor2.c

inherit ROOM;

void create()
{
	set("short", "回廊");
	set("long", @LONG
你现在正走在一条回廊上, 东北方是一座花木扶苏的天井, 穿过
东边的圆形拱门就可以回到大殿。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "north" : __DIR__"corridor6",
     "east" : __DIR__"temple1",
]));

	setup();
	replace_program(ROOM);
}
