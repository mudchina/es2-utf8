// Room: /d/snow/square.c

inherit ROOM;

void create()
{
	set("short", "广场");
	set("long", @LONG
这里是雪亭镇镇前广场的空地，地上整齐地铺著大石板。广场中央有
一个木头搭的架子，经过多年的风吹日晒雨淋，看来非常破旧。四周建筑
林立。往西你可以看到一间客栈，看来生意似乎很好。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"mstreet1",
		"west" : __DIR__"inn",
		"south" : __DIR__"sroad1",
		"east" : __DIR__"temple",
	]));
	set("objects", ([
//		__DIR__"npc/worker": 4
		"/d/snow/npc/trav_blade" : 3,
	  ]) );

	set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}
