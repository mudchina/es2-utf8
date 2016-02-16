inherit ROOM;

void create()
{
   set("short", "西厢房走道");
	set("long", @LONG
通过后厅走道，接著你走进西厢房走道。长长的走道中，纯金
成的长灯架上挂了一排饰丽的宫灯! 走道两旁摆设了许多奇花异草，
空气中弥漫一种淡淡的香气。在一柱柱雕饰华丽的长柱，刻画许多
彩绘的图形，美不胜收。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "north" :__DIR__"lroad3",
    "south" :__DIR__"wroad2",

]));

	setup();
	replace_program(ROOM);
}
