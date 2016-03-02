// jiyuan2.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "香茗坊二楼");
	set("long", @LONG
这是茶楼的二层，附近的文人墨客常喜欢在此品茗作赋。
    里首摆着个棋盘。
LONG
        );
        set("exits", ([
                "down"  : "/u/cloud/tearoom" ]) );

	set("objects", ([
                "/u/cloud/npc/chess_player" : 1,
	]) );

        setup();

}


