// Room: /d/snow/sroad1.c

inherit ROOM;

void create()
{
	set("short", "雪亭镇街道");
	set("long", @LONG
这里是雪亭镇的街道，往北是一个热闹的广场，南边是条小路通往
一座林子，东边则有一条小径沿著山腰通往山上，往西是一条比较窄的
街道，参差不齐的瓦屋之间传来几声犬吠。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"sroad2",
  "north" : __DIR__"square",
  "south" : "/u/cloud/dragonhill/nroad",
  "east" : __DIR__"eroad1",
]));
	set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}
