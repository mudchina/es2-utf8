#include <room.h>

inherit ROOM;

void create()
{
   set("short", "小花池");
	set("long", @LONG
LONG
	);
    set("objects", ([

      "/d/latemoon/npc/fuyun" : 1 ]) );

	set("exits", ([ /* sizeof() == 2 */
     "west" :__DIR__"bathroom1",

]));

	setup();
	replace_program(ROOM);
}
