// Room: /d/choyin/tomb2.c

inherit ROOM;

void create()
{
	set("short", "树王坟内部");
	set("long", @LONG
这里是树王坟树洞的内部，你的北、西、南三面都是盘根错节的树
根，地面上铺著一堆乾草，似乎有人睡过的样子，往东的出口通往树洞
的另一端。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"tomb1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
