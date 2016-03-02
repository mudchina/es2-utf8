// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
这是一条平整的石板路, 上面隐约可以看见两道很深的车轮, 看来
是用来作运输用途的道路. 往北是一条较小的碎石路通往村内. 东边有
一栋石屋, 旁边的空地堆了一些石料. 南边看去是一片矮树丛. 石板路
往西边延伸.

LONG
	);
    set("exits", ([
    "west" : __DIR__"path6",
    "north" : __DIR__"path4",
    "east" : __DIR__"station0",
]));
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
