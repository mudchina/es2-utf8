
#include <room.h>
inherit ROOM;

void create()
{
     set("short", "翠湘阁");
	set("long", @LONG
这是晚月庄的舞曲步法研究室, 名曰「翠湘」。墙上刻画著各种
基本步法与一些诗词曲赋。在每一位美女图的姿态形体之中，那种翩
然起舞的曼妙舞姿，含蕴许多珍贵奇妙的舞步。你可以看到几位师姐
一起走著奇特的步法，正在试著模拟这些舞步，一边低头沉思要如何
运用，十分的投入。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "south" :__DIR__"upstar4",

]));

    set("objects", ([
        __DIR__"npc/shinfun" : 1,
    ]) );
    create_door("south","木门","north", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
