// Room: /d/death/road1.c

inherit ROOM;

void create()
{
	set("short", "鬼门大道");
	set("long", @LONG
你走在一条阴森森的路上, 浓浓的雾环绕在你的四周, 好像永
远都不会散去似的. 往南看去你勉强可以分辨出一个城楼的模样,
往北隐约可以看到几盏灯笼, 在浓雾中显得格外的诡异. 路的两旁
各有一栋木造的建筑, 门都是半开的, 但你看不清楚里面有什么.

LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/death/road2",
  "south" : "/d/death/gateway",
  "west" : "/d/death/inn1",
  "east" : "/d/death/inn2",
]));

	setup();
}

