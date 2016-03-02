// jiyuan2.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "怡红院二楼");
	set("long", @LONG
这是怡红院的姑娘们陪客人们饮酒品茗，吟诗作赋的地方，甚是幽
雅。
LONG
        );
        set("exits", ([
                "down"  : "/u/cloud/jiyuan" ]) );

	set("objects", ([
                "/u/cloud/npc/girl" : 1,
	]) );

        setup();

}


