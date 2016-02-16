
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "后厅");
	set("long", @LONG
你进了后厅，这是后院上房五间中，最大的一间厅房。四面墙            
壁，玲珑剔透，琴剑书画，挂在墙上。锦笼纱罩，金彩珠光，连地上                  
踏的砖，皆是碧绿凿花，是雕空的紫檀板壁。厅上摆了二十六张桧木
交椅，庄内对外展示舞步表演，都是在这举行。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "east" :__DIR__"lroad1",
     "north" :__DIR__"twoc",
     "west" :__DIR__"lroad3",
     "south" :__DIR__"lstudio",

]));

    set("objects", ([
        __DIR__"npc/spring2" : 1,
        __DIR__"npc/yushou" : 1,
    ]) );
    create_door("north","后厅大门","south", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
