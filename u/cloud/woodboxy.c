// woodboxy.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "棺材铺");
	set("long", @LONG
你现在正站在棺材铺里
    靠近门口的地方有一块乌木雕成的招牌(sign)。
LONG
        );
        set("exits", ([
                "east"          : "/u/cloud/nwroad2",
                "west"          : "/u/cloud/god1"
                      ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
        create_door("west", "木门", "east", DOOR_CLOSED);
        set("objects", ([
                "/u/cloud/npc/box_boss" : 1,
		"/u/cloud/npc/box_waiter" : 8,
 ]) );
        setup();

}

string look_sign(object me)
{
        return "招牌写著：棺。\n";
}

