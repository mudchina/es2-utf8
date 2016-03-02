// tea_corridor.c

#include <room.h>

inherit ROOM;

string look_sign();

void create()
{
	set("short", "香茗坊茶窖");
	set("long", @LONG
茶窖里有几个大竹箩，里面装满了茶叶。 
LONG
        );

        set("exits", ([
                "south"          : "/u/cloud/tearoom",
	]) );

//	set("objects", ([
//	]) );

        create_door("south", "木雕门", "north", DOOR_CLOSED);

        setup();

}


