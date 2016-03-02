// Room: /d/city/house1.c

inherit ROOM;

void create()
{
	set("short", "空房间");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"street11",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
