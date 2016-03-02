#include <room.h>

inherit ROOM;

void create()
{
   set("short", "内厅");
	set("long", @LONG
你进了内厅，迎面挂著葱绿洒花软帘，掀帘进去，抬头一看，
只见四面墙壁，玲珑剔透，琴剑书画，挂在墙上。锦笼纱罩，金彩
珠光，连地上踏的砖，皆是碧绿凿花，左一架书，右一架屏。四面
是雕空的紫檀板壁。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "south" :__DIR__"miroom",

]));
    set("objects", ([
        __DIR__"npc/shaowei" : 1,
    ]) );
    create_door("south","垂花门","north", DOOR_CLOSED);

	setup();
	replace_program(ROOM);
}
