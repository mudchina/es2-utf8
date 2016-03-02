// Room: /d/green/path3.c

inherit ROOM;

void create()
{
	set("short", "三叉路口");
	set("long", @LONG
你来到一条三叉路口, 往东看去是另一条更小更窄的黄土路, 主要
道路是南北向的, 西边有一栋民宅.
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/green/path2",
  "south" : "/d/green/path4",
  "west" : "/d/green/house0",
  "east" : "/d/green/path8",
]));
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
