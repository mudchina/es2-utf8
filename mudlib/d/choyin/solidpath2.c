// Room: /d/choyin/solidpath2.c

inherit ROOM;

void create()
{
	set("short", "荒野小径");
	set("long", @LONG
荒野中的小路,依稀可变,蜿蜒曲折,不知通向何方.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"cloudpool",
  "south" : __DIR__"solidpath1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
