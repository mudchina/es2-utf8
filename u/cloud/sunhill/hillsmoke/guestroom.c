// u/sunhill/hillsmoke/guestroom.c

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "香客斋");
        set("long", @LONG
这里是山烟寺的客房，
LONG
        );
        set("exits", ([
                "east" : __DIR__"yard",
        ]));
        set("item_desc", ([
                "sign": @TEXT
广结善缘，普渡众生。
TEXT
        ]) );

        set("objects", ([
                "/u/cloud/npc/monk_waiter":1,
        ]) );
        setup();
}
