// Room: /u/k/karrimor/temple/restroom.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "厢房");
	set("long", @LONG
这是一间供香客或其他江湖同道休息挂单的客房, 屋子里只是简
单地摆放著几件家俱。从西边的天井中, 传来了阵阵的花香。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
            "west" : __DIR__"corridor7",
]));

        set("objects", ([
            "/d/temple/npc/old_taoist" : 1 ]) );

        create_door("west", "木门", "east");

	setup();
}
