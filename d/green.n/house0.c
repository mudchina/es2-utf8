// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "民宅");
	set("long", @LONG
这是一间简陋的民宅，阴暗窄小的屋内散著一地的柴火和各式工具。
屋角的石炉上闪著微弱的火光，一锅不知是什么的东西正冒出阵阵香味。
另一角放著一张简陋的木床和几张椅子。
 
LONG
	);
    set("exits", ([
    "east" : __DIR__"path3",
]));
	set("objects", ([
    __DIR__"npc/woman1" : 1,
    __DIR__"npc/woman2" : 1,
		]) );

	setup();
	replace_program(ROOM);
}
