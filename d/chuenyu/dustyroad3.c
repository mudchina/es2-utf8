// Room: /d/chuenyu/dustyroad2.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "青石小路");
        set("long", @LONG
这是一条通向一所民宅的青石小路。小屋就在你的东北方向。一个
整洁的小草坪在你的东边。西南方向是一个三叉路口，你似乎可以听到
卖花姑娘清脆的叫卖声。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "southwest" : __DIR__"croad2",
          "northeast" : __DIR__"home",
            "north" : __DIR__"sunnyroad",
]));
        create_door("northeast", "木门", "southwest", DOOR_CLOSED);
        
        set("outdoors", "chuenyu");
        setup();
        replace_program(ROOM);
}

                            
