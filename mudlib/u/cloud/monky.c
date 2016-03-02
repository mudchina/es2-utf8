// monky.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "斋院");
	set("long", @LONG
你现在正站在斋院里
    靠近门口的地方有一块乌木雕成的招牌(sign)。
LONG
        );
        set("exits", ([
                "north"          : "/u/cloud/wroad2" ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
        set("objects", ([
		"/u/cloud/npc/monk" : 1,
		"/d/snow/npc/beggar" : 2,
		"/obj/example/dumpling" : 3,
	]) );

        setup();

}

string look_sign(object me)
{
        return "招牌写著：善。\n";
}

