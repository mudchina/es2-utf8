// Room: /u/k/karrimor/temple/corridor6.c

inherit ROOM;

void create()
{
	set("short", "回廊");
	set("long", @LONG
你正走在一条回廊之上, 回廊往南北延伸, 两端分别连接著大殿
及后殿。东边是一座花草扶苏的天井, 西边是一间上了锁的房间。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
     "south" : __DIR__"corridor2",
     "north" : __DIR__"corridor4",
     "east" : __DIR__"inneryard",
]));

	setup();
	replace_program(ROOM);
}
