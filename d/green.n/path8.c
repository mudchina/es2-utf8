// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "小巷子");
	set("long", @LONG
这是一条小小的巷子，地上铺著碎石和黄土。南北各有一栋建筑，不
过南方的屋子出口不在这边。往东可以看到一个小小的广场，往西则是一
个三岔路口。
 
LONG
	);
    set("exits", ([
    "west" : __DIR__"path3",
    "north" : __DIR__"house1",
    "east" : __DIR__"field0",
]));
	set("outdoors", "green");
	set("objects", ([
    __DIR__"npc/kid3" : 2,
	]) );

	setup();
	replace_program(ROOM);
}
