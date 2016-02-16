// Room: /d/oldpine/npath2.c

inherit ROOM;

void create()
{
	set("short", "林间小路");
	set("long", @LONG
你现在正走在一条林间的小路上，小路两旁长满了高耸的松树，从
林间传来阵阵鸟叫声，小路往南北两个方向延伸出去。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/d/oldpine/npath3",
  "north" : "/d/oldpine/npath1",
]));
	set("outdoors", "oldpine");

	setup();
	replace_program(ROOM);
}
