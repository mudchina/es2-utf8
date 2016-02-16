// jiyuan.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "怡红院");
        set("long", @LONG
你现在正站在怡红院里
    靠近门口的地方有一块乌木雕成的招牌(sign)。
LONG
        );
        set("exits", ([
                "south"  : "/u/cloud/eroad1", 
                "up"  : "/u/cloud/jiyuan2",
        ]) );

        set("objects", ([
                "/u/cloud/npc/mother" : 1,
        ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "招牌写著：怡红院\n";
}

