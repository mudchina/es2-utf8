// Room: /d/green/house0.c

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
	set("exits", ([ /* sizeof() == 1 */
  "east" : "/d/green/path3",
]));
	set("objects", ([
	"/d/green/npc/woman1" : 1,
	"/d/green/npc/woman2" : 1,
		]) );

	setup();
	replace_program(ROOM);
}
