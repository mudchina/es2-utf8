
#include <room.h>
inherit ROOM;

void create()
{
    set("short","后院走道");
	set("long", @LONG
你走在一条长廊上，两旁都是庭台堂庑，廊上弥漫著一股
香郁的气息，廊下是由青石砖铺成，一边接后厅内院，一边的
尽头则是一幅大石壁画，西侧似有一铜门(door)。
有一间书房。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "west" :__DIR__"latemoon6",
    "south" :__DIR__"latemoonc",

]));

     create_door("west","铜门","east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
