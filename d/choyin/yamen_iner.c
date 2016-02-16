// Room: /d/choyin/yamen_iner.c

inherit ROOM;

void create()
{
	set("short", "内厅");
	set("long", @LONG
内厅是老爷与好友叙话, 品茶, 吟诗, 作画之所; 格外幽静......
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yamen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
