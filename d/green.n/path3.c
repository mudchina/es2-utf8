// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "三叉路口");
	set("long", @LONG
你来到一条三叉路口, 往东看去是另一条更小更窄的黄土路, 主要
道路是南北向的, 西边有一栋民宅.

LONG
	);
    set("exits", ([
    "north" : __DIR__"path2",
    "south" : __DIR__"path4",
    "west" : __DIR__"house0",
    "east" : __DIR__"path8",
]));
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
