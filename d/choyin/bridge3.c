// Room: /d/choyin/bridge3.c

inherit ROOM;

void create()
{
	set("short", "曲桥");
	set("long", @LONG
这是一座弯弯曲曲的曲桥，横过翠柳湖连接东岸的雨桥庄跟西岸的
乔阴县城，从这里可以欣赏翠柳湖的美景，许多睡莲散布在桥墩四周，
湖面飘著数不尽的浮萍，浮萍底下有不少艳红锦鲤穿梭来去。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"bridge2",
  "east" : __DIR__"bridge4",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");
	set("objects", ([
		 __DIR__"npc/visitor" : 4
 	]) );

	setup();
	replace_program(ROOM);
}
