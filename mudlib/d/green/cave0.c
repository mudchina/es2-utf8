// tmp cave room until the cave section is done.
#include <room.h>
 
inherit ROOM;
 
void create()
{
        set("short", "洞口");
        set("long", @LONG
这里是山洞的入口, 往南看去是一条小小的碎石路, 两旁长满
杂草, 看来很不明显. 往北是一道厚厚的木门, 上面用一条手臂粗
的铁链拴著. 虽然如此, 你仍可以感到一股寒气从里面透出来.
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/green/path0",
  "north" : "/d/green/cave1",
]));
	create_door("north","木门","south",DOOR_CLOSED); 
	set("objects", ([
		"/d/green/npc/kid4" : 2,
		]) );
        setup();
        replace_program(ROOM);
}
 
