// duchang.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "赌场");
	set("long", @LONG
你现在正站在赌场里。靠近门口的地方有一块乌木雕成的招牌(sign)。
LONG
        );
        set("exits", ([
          "north": __DIR__"eroad1", 
          "up": __DIR__"duchang2",
        ]) );

        set("item_desc", ([
          "sign": "招牌上写着：赌，胜者赢双。\n",
        ]) );

        set("objects", ([
          "/u/cloud/npc/judge" : 1,
        ]) );
 
        setup();

}
