// Room: /d/temple/broom2.c

inherit ROOM;

void create()
{
	set("short", "书库");
	set("long", @LONG
这是一间什么也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : "/d/temple/broom1",
]));

	setup();
	replace_program(ROOM);
}
