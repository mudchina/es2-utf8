// Room: /d/village/road2.c

inherit ROOM;

void create()
{
	set("short", "三叉路口");
	set("long", @LONG
这里已经离天驼关很远了，顺着黄土大道向南走，绿色渐渐多了起
来，树木透着喜人的绿，放眼望去青山绿水，好一派关内景色，你能看
到散落的房屋，农田和水塘。来往的旅客、商人、农民也多了。黄土大
道向东南方向延伸，西面是进入一个村庄的小路。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south"	 	 : "/d/city/nroad2",
  "north" : __DIR__"road1",
  "west" : __DIR__"road3",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/trader1" : 2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
