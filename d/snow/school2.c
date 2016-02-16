// Room: /d/snow/school2.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "淳风武馆教练场");
	set("long", @LONG
你现在正站在一个宽敞的教练场中，地上铺著黄色的细砂，许多人
正在这里努力地操练著，北边是一间高大的兵器厅，往东则是武馆师父
们休息的大厅。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : "/d/snow/weapon_storage",
  "west" : "/d/snow/school1",
  "east" : "/d/snow/schoolhall",
]));
	set("objects", ([ /* sizeof() == 2 */
  "/d/snow/npc/trainee" : 6,
  "/d/snow/npc/fist_trainer" : 1,
]));
	set("outdoors", "snow");

	create_door("west", "红漆大门", "east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
