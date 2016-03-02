// butchery.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "镇北肉铺");
	set("long", @LONG
你现在正站在镇北肉铺里，肉架上挂满了血淋淋的生肉，一股腥
气扑面而来，不时有几只苍蝇在屋里飞来飞去。
    靠近门口的地方有一块牛骨雕成的招牌(sign)，上面写着些
什么。
LONG
        );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        set("exits", ([
                "east"          : "/u/cloud/nwroad1" ]) );

        set("objects", ([
                "/u/cloud/npc/butcher" : 1,
		"/u/cloud/npc/fly.c" : 6,
 ]) );

        setup();

}

string look_sign(object me)
{
        return (@LONG
本店即将收购死狗。
LONG);
}

