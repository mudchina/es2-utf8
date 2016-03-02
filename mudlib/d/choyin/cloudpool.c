// Room: /d/choyin/cloudpool.c

inherit ROOM;

void create()
{
	set("short", "云梦大泽");
	set("long", @LONG
云梦大泽八百里,雾气沼沼,商旅绝行.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"solidpath2",
]));
        set("objects",([
            "/d/choyin/npc/serpent":4,
                      ]) );
        set("resource/water",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
