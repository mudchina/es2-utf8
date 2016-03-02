// u/sunhill/hillsmoke/woodroom.c

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "柴房");
        set("long", @LONG
这里是山烟寺的柴房，
LONG
        );
        set("exits", ([
                "west" : __DIR__"yard",
        ]));

        set("objects", ([
                "/u/cloud/npc/monk_guard":1,
        ]) );
        setup();
}
