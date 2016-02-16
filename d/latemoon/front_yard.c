#include <room.h>

inherit ROOM;

void create()
{
	set("short", "晚月庄前庭");
	set("long", @LONG
一走入这个庭园，扑鼻而来的便是一股若有似无，但是又沁人心
脾的花香，庭园甚是宽敞，许多奇花异石错落其间，显是经过高手匠
人的精心布置，西边花丛间可看到主屋的屋角，一条石板小径沿著假
山通往主屋。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"out" :__DIR__"gate",
		"west" :__DIR__"latemoon1",
        "south" :__DIR__"park/yard1",
	]));
    set("outdoors", "latemoon");

	setup();
	replace_program(ROOM);
}

