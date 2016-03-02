// Room: /d/village/lordhouse2.c

inherit ROOM;

void create()
{
	set("short", "财主家东房");
	set("long", @LONG
东房内的北面摆放着很大的八仙桌，桌子的后面是供奉关公的神龛，
神龛上三根拇指粗细的香慢慢燃着，关公的手似乎指向前面的墙壁(wall)，
你还是第一次见到如此奇特姿势的关公像。在墙角处放着一根铁棍(stick)，
顺着东侧打开的窗子望出去，可以看到远远的官道上来来往往的人群和遥
远处阴森的黑松山。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lordhouse1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
