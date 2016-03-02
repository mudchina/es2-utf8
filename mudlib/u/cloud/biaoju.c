// biaoju.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "镖局");
        set("long", @LONG
你现在正站在镖局里
    靠近门口的地方有一块乌木雕成的招牌(sign)。
LONG
        );
        set("exits", ([
                "north"          : "/u/cloud/eroad2" ]) );

        set("objects", ([
                "/u/cloud/npc/b_header" : 1,
                "/u/cloud/npc/bfighter" : 1,
        ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
	set("valid_startroom", 1);
        setup();

}

string look_sign(object me)
{
        return "招牌写著：镖。\n";
}

