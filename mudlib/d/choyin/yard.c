// Room: /d/choyin/yard.c

inherit ROOM;

void create()
{
	set("short", "庭院");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"club",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
