// croad1.c
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "黄土大道");
        set("long", @LONG
你正走在一条黄土大道上。路上尘土飞扬，路旁稀疏几棵矮树。
往南通往京师，东北是通往天驼关的大道。
LONG
        );

        set("exits", ([
                "south"      : "/d/village/road1",
		"north" 	 : __DIR__"croad2" ]) );

/*        set("objects", ([
                "/u/cp/chater2" : 1, ]) );*/
        set("outdoors", "chuenyu");
        setup();
        replace_program(ROOM);
}

