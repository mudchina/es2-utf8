
#include <room.h>
inherit ROOM;

void create()
{
     set("short", "前堂楼");
	set("long", @LONG
这里是庄院二楼的前堂楼，有著传统的古式建筑风格。由上好的        
桧木搭建而成, 东面一阵耀眼的的白光由两扇敞开的落地窗口射进来
，泛映出一种清新幽静的格局。开了楼门出去可以一览庄院内外的山
川景色，欣赏其美丽景观。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "east" :__DIR__"uplook",
    "north" :__DIR__"upstar4",
    "south" :__DIR__"upstar3",

]));

    create_door("east","楼门","west", DOOR_CLOSED);
    setup();
	replace_program(ROOM);
}
