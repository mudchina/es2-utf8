#include <room.h>
inherit ROOM;

void create()
{
        set("short", "储藏室");
        set("long", @LONG
一个小小的储藏室。四壁上布满了灰尘。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "north" : __DIR__"west_blackge",
        ]));
        set("objects", ([
        "/obj/longsword" : 5,
        ]) );
        
        create_door("north", "木门", "south", DOOR_CLOSED);
        setup();
}

                