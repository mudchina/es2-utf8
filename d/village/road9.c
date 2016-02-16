// Room: /d/village/road9.c

inherit ROOM;
#include <room.h>

void create()
{
	set("short", "青石小路");
	set("long", @LONG
两只小燕子落到柳枝上，叽叽喳喳叫个不停，它们的家可能在附近。
在小路的西面是一片绿油油的稻田，几个农民在田间忙碌；东面是地主田
老财的宅院，难得一个地主的房子并不是特别奢华，只有三间屋子。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"road8",
  "west" : __DIR__"field",
  "east" : __DIR__"lordhouse1",
]));
	create_door("east","田老财家大门","west",DOOR_CLOSED);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
