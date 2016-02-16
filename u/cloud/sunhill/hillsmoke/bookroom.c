// u/sunhill/hillsmoke/bookroom.c

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "藏经阁");
        set("long", @LONG
这里是山烟寺的藏经阁，
LONG
        );
        set("exits", ([
                "northwest" : __DIR__"hall",
        ]));
        set("item_desc", ([
                "sign": @TEXT
广结善缘，普渡众生。
TEXT
        ]) );

        set("objects", ([
                "/u/cloud/npc/monk_guard":1,
        ]) );
        setup();
}
