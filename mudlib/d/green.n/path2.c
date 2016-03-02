// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "三叉路口");
	set("long", @LONG
小路到了这里往北就算是出了村子. 西边有一间小小的土地庙, 东
边是一栋民宅似的建筑, 不过入口不在这边. 往南是一个交叉路口.

LONG
	);
    set("exits", ([
    "south" : __DIR__"path3",
    "north" : __DIR__"path1",
    "west" : __DIR__"temple0",
]));
	set("outdoors", "green");
	set("objects", ([
    __DIR__"npc/kid2" : 2,
	]) );

	setup();
	replace_program(ROOM);
}
