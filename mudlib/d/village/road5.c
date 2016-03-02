// Room: /d/village/road5.c

inherit ROOM;

void create()
{
	set("short", "青石小路");
	set("long", @LONG
青石小路在这里分成两条，一条继续向西延伸，另一条伸向南面，北
面是一个鲜花盛开的小花园，闻到阵阵花香，你不仅心旷神怡。西面遥远
处是连绵的群山，东南是一片面积不小的湖泊。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"road6",
  "north" : __DIR__"littlegarden",
  "southdown" : __DIR__"road7",
  "east" : __DIR__"road4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
