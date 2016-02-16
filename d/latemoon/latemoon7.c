
#include <room.h>
inherit ROOM;

void create()
{
     set("short","后院走道");
	set("long", @LONG
你走在一条长廊上，两旁都是庭台堂庑，廊上弥漫著一股
香郁的气息，长廊向东西方延伸而去。东边是后厅院子，西边
有一间书房。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "south" :__DIR__"latemoon8",
    "east" :__DIR__"latemoonc",
    "west" :__DIR__"latebook",

]));

   create_door("south","石门","north", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
