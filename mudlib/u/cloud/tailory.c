// tailory.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "布庄");
	set("long", @LONG
你现在正站在布庄里
    靠近门口的墙壁上挂着(sign)。
LONG
        );
        set("exits", ([
                "north"          : "/u/cloud/nwroad2" ]) );

        set("objects", ([
                "/u/cloud/npc/tailor" : 1,
 ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "招牌写著：衣。\n";
}

