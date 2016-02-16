// zaihuoy.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "杂货铺");
	set("long", @LONG
你现在正站在杂货铺里
    靠近门口的地方有一块乌木雕成的招牌(sign)。
LONG
        );
        set("exits", ([
		"north"		: "/u/cloud/nwroad3",
                "east"          : "/u/cloud/nroad2" ]) );

	set("objects", ([
                "/u/cloud/npc/seller" : 1,
 ]) );

        set("item_desc", ([
                "sign": (: look_sign :)
        ]) );

        setup();

}

string look_sign(object me)
{
        return "招牌写著：商。\n";
}

