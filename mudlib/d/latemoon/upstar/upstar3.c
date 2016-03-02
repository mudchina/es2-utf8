
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "二楼走廊");
	set("long", @LONG
你走在后厅二楼的走廊上，庄内像这样的走廊很多，你若没有地
理概念很容易迷路。长长的走道中, 纯金铸成的长灯架上挂了一排饰
丽的宫灯! 入夜之后灯火辉煌! 十分美丽!
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "west" :__DIR__"upstar2",
    "north" :__DIR__"upstarc",
    "south" :__DIR__"uproom3",

]));

    create_door("south","木门","north", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
