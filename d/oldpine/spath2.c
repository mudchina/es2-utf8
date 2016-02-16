// Room: /d/oldpine/spath2.c

inherit ROOM;

void create()
{
	set("short", "下坡道");
	set("long", @LONG
这是一条笔直的坡道，北高南低，道路两旁长满了许多松树，从松
林间隐约可以听到东边传来流水的声音。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"spath1",
  "north" : __DIR__"spath3",
]));
	set("no_clean_up", 0);
	set("outdoors", "oldpine");

	setup();
	replace_program(ROOM);
}
