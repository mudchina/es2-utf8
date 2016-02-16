// Room: /d/choyin/solidpath1.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
黄土铺就的小路.阴雨天,泥泞难行.往南就上山了.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"e_gate",
  "south" : __DIR__"rockpath2",
  "north" : __DIR__"solidpath2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
