// u/sunhill/hillsmoke/hall.c

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "山烟寺大殿");
        set("long", @LONG
这里是山烟寺的大殿，
LONG
        );
        set("exits", ([
                "north" : __DIR__"yard",
		"southwest" : __DIR__"studyroom",
		"southeast" : __DIR__"bookroom",
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
        "/u/cloud/board/bonze_b"->foo();
}
