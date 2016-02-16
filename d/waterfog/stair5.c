// Room: /d/waterfog/stair5.c

inherit ROOM;

void create()
{
	set("short", "白石阶梯");
	set("long", @LONG
你现在正走在一条长长的白石阶梯上，阶梯随著山峰蜿蜒盘旋，宛
如一条白龙，水烟阁就矗立在北边的山峰顶上，即使是从这么近的距离
你仍然感觉这座楼阁飘飘渺渺，难以捉摸。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : "/d/waterfog/frontyard",
  "eastdown" : "/d/waterfog/clifftop",
]));
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
