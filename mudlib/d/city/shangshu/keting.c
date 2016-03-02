// /d/city/street5

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "尚书府客厅");
        set("long",@LONG
这里是尚书府的会客厅，平常主人就在此接待客人。客厅的装饰
倒并不多，但都极其讲究。所有的家具都是用沉香木做的，时时发出
一股淡淡的香味。家具被擦得一尘不染的，整齐地排列在两旁。当中
的椅子尤其大，并铺以少见的白虎皮。
LONG
        );

        set("exits", ([
                "west" :        __DIR__"yuan",
                ]));

	set("objects", ([
		__DIR__"npc/shangshu":	1,
		]));

        setup();
        replace_program(ROOM);
}

