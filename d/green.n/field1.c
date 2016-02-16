// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "采石场的空地");
	set("long", @LONG
这是一片黄土空地，四周堆著一些切割整齐的大石块和碎石。往东看
去就是采石场，高耸的石璧经过多年的采挖已经看不出原来的模样了。往
南看去是一些矮小的房舍和储存工具的地方，往西是村内的广场，往北靠
近广场的地方有一栋简陋的民宅。一条不是很明显的小路延著民宅往东北
方通去。
 
LONG
	);
    set("exits", ([
    "west" : __DIR__"field0",
    "south" : __DIR__"station1",
    "north" : __DIR__"house3",
    "northeast" : __DIR__"field2",
]));
	set("objects", ([
    __DIR__"npc/kid1" : 1,
	]) );
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
