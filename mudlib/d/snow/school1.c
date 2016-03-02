// Room: /d/snow/school1.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "淳风武馆大门");
	set("long", @LONG
你现在正站在一间大宅院的入口，两只巨大的石狮镇守在大门的两
侧，一阵阵吆喝与刀剑碰撞的声音从院子中传来，通过大门往东可以望
见许多身穿灰衣的汉子正在操练。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/snow/mstreet1",
  "east" : "/d/snow/school2",
]));
	set("outdoors", "snow");
	set("objects", ([
		__DIR__"npc/guard": 1 ]) );

	create_door("east", "红漆大门", "west", DOOR_CLOSED);

	setup();
	replace_program(ROOM);
}
