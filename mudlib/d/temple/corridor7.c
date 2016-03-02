// Room: /u/k/karrimor/temple/corridor7.c

inherit ROOM;

void create()
{
	set("short", "回廊");
	set("long", @LONG
你正走在一条回廊之上, 回廊往南北延伸, 两端分别连接著大殿
及后殿。西边是一座花草扶苏的天井, 东边则是一排厢房。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
     "north" : __DIR__"corridor3",
     "south" : __DIR__"corridor1",
     "west" : __DIR__"inneryard",
     "east" : __DIR__"restroom1",
]));

    create_door("east","木门","west");

	setup();
}
