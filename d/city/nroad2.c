// nroad2.c
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "北驿道");
        set("long", @LONG
这是一条青石铺地的大驿道，地处京师的北郊。北方入京必经
此地。
    往南走就可以到京师了。东北是连绵的群山。
LONG
        );

        set("exits", ([
                "south"          : __DIR__"nroad1",
                "north"          : "/d/chuenyu/croad3" ]) );

        set("objects", ([
                "/u/cp/chater2" : 1, ]) );
        set("outdoors", "city");
        setup();
        replace_program(ROOM);
}

