// Room: /d/green/field1.c

inherit ROOM;

void create()
{
	set("short", "采石场的空地");
	set("long", @LONG
这是一片黄土空地，四周堆著一些切割整齐的大石块和碎石。往东看
去就是采石场，高耸的石璧经过多年的采挖已经看不出原来的模样了。往
南看去是一些矮小的房舍和储存工具的地方，往西是村内的广场，往北靠
近广场的地方有一栋简陋的民宅。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : "/d/green/field0",
  "south" : "/d/green/station1",
  "north" : "/d/green/house3",
]));
	set("objects", ([
	"/d/green/npc/kid1" : 1,
	]) );
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
