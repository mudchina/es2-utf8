// Room: /d/choyin/rockpath2.c

inherit ROOM;

void create()
{
	set("short", "青石小路");
	set("long", @LONG
    铺路的青石采自桐柏山.因行人稀少,已快被茅草遮没.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"solidpath1",
  "southup" : __DIR__"rockpath1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
