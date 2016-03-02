// Room: /d/choyin/yamen_yard.c
# include <room.h>
inherit ROOM;

void create()
{
	set("short", "县衙内院");
	set("long", @LONG
院内草木繁茂,亭榭错落有致,可见这位县太爷也是位雅人.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"court1",
  "north" : __DIR__"yamen",
]));
   create_door("north", "铜钉大门", "south", DOOR_CLOSED);   	
        set("no_clean_up", 0);
        set("objects", ([
                __DIR__"npc/magistra" : 4     
                         ]) ); 
	setup();
      replace_program(ROOM);
}
