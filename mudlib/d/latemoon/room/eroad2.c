inherit ROOM;

void create()
{
   set("short", "东厢房走道");
	set("long", @LONG
通过后厅走道，接著你走进东厢房走道。除了长长的走道中，
一排饰丽的宫灯! 走道两旁摆设了许多奇花异草，各有各的特色与
形态，空气中弥漫一种淡淡的香气。往南通往东厢房。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "north" :__DIR__"lroad1",
    "south" :__DIR__"eroad1",

]));

	setup();
	replace_program(ROOM);
}
