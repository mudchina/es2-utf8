// Room: /d/canyon/stone_forest2.c

inherit ROOM;

void create()
{
	set("short", "黄石穿林路");
	set("long", @LONG
草压天顶的情况依旧，唯西侧亮光逐渐显明，看来西侧的不远处
有一出口，黄石斑斑，挟杂著白色的圆点，像是白色光束长期照射的
结果，蒙胧的景色在此总算完全的清淅了，向东侧仍是回到路口的路
，而西侧的亮光直直吸引你往深处探索。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"stone_forest3",
		"east" : __DIR__"stone_forest1",
]));

	setup();
	replace_program(ROOM);
}
