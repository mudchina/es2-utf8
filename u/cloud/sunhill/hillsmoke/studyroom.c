// u/sunhill/hillsmoke/studyroom.c

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "方丈");
        set("long", @LONG
这里是山烟寺的方丈，
LONG
        );
        set("exits", ([
                "northeast" : __DIR__"hall",
        ]));
        set("item_desc", ([
                "sign": @TEXT
广结善缘，普渡众生。
TEXT
        ]) );

        set("objects", ([
                "/daemon/class/bonze/master.c":1,
        ]) );
        set("valid_startroom", 1);
        setup();
}
