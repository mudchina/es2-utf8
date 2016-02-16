// /d/city/street5

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "尚书府大门");
        set("long",@LONG
你来到尚书府大门。门上悬挂着一块很大的黑色牌匾，上面用隶
书写着三个金字「尚书府」。牌匾上的一行小字表明这是当今皇上所
题，可以看出其官势显赫。
LONG
        );

        set("exits", ([
                "west" :        "/d/city/street3",
                "east" :        __DIR__"yuan",
                ]));

	set("objects", ([
		__DIR__"npc/guard":	1,
		]));

        set("outdoors", "city");

	create_door ("east", "大铁门", "west", DOOR_CLOSED);

        setup();
}

int valid_leave(object me,string dir)
{
        if ( dir=="east" &&  present("guard", environment(this_player()))
		&& !(string)me->query("marks/尚书") )
        return notify_fail("门房伸手拦住了你的去路，喝道：闯什么闯！\n");

	if ((string)me->query("marks/尚书") )
		me->set("marks/尚书",0);
        return ::valid_leave(me,dir);
}

