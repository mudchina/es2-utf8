// Room: /d/snow/eroad2.c

inherit ROOM;

void create()
{
	set("short", "黄土小径");
	set("long", @LONG
这是一条普通的黄土小径，小径往西南通往一处山间的平地，从这
里可以望见不少房屋错落在平地上，往北则一路上山。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"eroad3",
  "west" : __DIR__"eroad1",
]));
	set("outdoors", "snow");

	set("objects", ([
		__DIR__"npc/dog": 2 ]) );

	setup();
	replace_program(ROOM);
}
