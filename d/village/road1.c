// Room: /d/village/road1.c

inherit ROOM;

void create()
{
	set("short", "黄土大道");
	set("long", @LONG
这条黄土大道很宽阔，足够供八架马车并驾齐驱，与异族交战时，大量
军队从此经过，和平时期只有商人来来往往。这条大道向南通往京师，往北
到天驼关。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road2",
  "north" : "/d/canyon/canyon7",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
