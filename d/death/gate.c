// Room: /d/death/gate.c

inherit ROOM;

void create()
{
	set("short", "[1;37m鬼门关[2;37;0m");
	set("long", @LONG
这里就是著名的阴间入口「鬼门关」，在你面前矗立著一座高大的
黑色城楼，许多亡魂正哭哭啼啼地列队前进，因为一进鬼门关就无法再
回阳间了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"bridge",
		"north" : __DIR__"gateway",
]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/wgargoyle" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
