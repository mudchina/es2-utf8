// Room: /d/canyon/dream/tmp.c

inherit ROOM;

void create()
{
	set("short", "幻影道入口");
	set("long", @LONG
整修中，请往回走:P
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"down" : "/d/canyon/fantasy1",
]));

	setup();
	replace_program(ROOM);
}
