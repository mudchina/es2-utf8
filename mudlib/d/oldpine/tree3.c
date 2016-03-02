// Room: /d/oldpine/tree3.c

inherit ROOM;

void create()
{
	set("short", "大松树顶");
	set("long", @LONG
哇....你终于爬上这株松树的树顶了，一阵阵凉风从四面八方吹来
，使你觉得心旷神怡，虽然你的经验告诉你在这种地方往下看是十分不
智的，但是你还是忍不住看了一眼，这里离地面至少也有十五、六丈高
，一阵晕眩警告你最好在跌下去以前离开这个地方。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : "/d/oldpine/tree2",
]));
	set("outdoors", "oldpine");

	setup();
	replace_program(ROOM);
}
