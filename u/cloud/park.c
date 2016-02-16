// park.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "张家花园");
	set("long", @LONG
你现在正站在张家花园里
LONG
        );
        set("exits", ([
                "south"          : "/u/cloud/eroad2" 
        ]) );
        set("objects", ([
                "/u/cloud/npc/thief" : 1,
        ]) );

        setup();

}

