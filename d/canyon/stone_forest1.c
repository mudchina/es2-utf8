// Room: /d/canyon/stone_forest1.c

inherit ROOM;

void create()
{
	set("short", "黄石穿林路路口");
	set("long", @LONG
四周是一大遍的林地，草高于三四十尺，再加上雾盲盲的景象，
使你不得不沿著黄石铺成的小路快步行走，深恐林草压顶，界时将不
知所措，向东深入似乎有一奇特的光亮，但距离太远，你看不清楚到
底是怎么著一回事。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"canyon2",
		"west" : __DIR__"stone_forest2",
]));
	set("shorst", "黄石穿林路路口");

	setup();
	replace_program(ROOM);
}
