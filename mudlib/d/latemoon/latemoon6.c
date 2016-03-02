#include <room.h>

inherit ROOM;

void create()
{
    set("short","禁闭房");
	set("long", @LONG
这里四面都是单调的墙壁(wall)。通常庄内弟子犯错就是
关在这儿！反省思过。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
      "east" :__DIR__"latemoon5",
]));

        set("item_desc", ([
                "wall": @TEXT
    你仔细观看石墙，突然发现原本单调的墙上隐隐约约出现了
一幅渺渺茫茫，似有似无的景像。彷佛是幻境，但又似真实，你
清楚的看到一首词：「梦里消魂无说处，觉来惆怅消魂误。」
TEXT
        ]) );

      set("objects", ([
         __DIR__"npc/funlin" : 1 ]) );
     create_door("east","铜门","west", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
