// tea_corridor.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "场院前厅");
	set("long", @LONG
    这里是这座场院的前厅，简单的陈设中透出一股尊贵不凡的气派。
一张黑漆镶金的八仙桌摆放在大厅中央，两只黝黑的太师椅座在这张桌
子的两旁。
LONG
        );

        set("exits", ([
                "east"          : "/u/cloud/god1",
	]) );

	set("objects", ([
	"/u/cloud/npc/god" : 1,]) );

        setup();

}


