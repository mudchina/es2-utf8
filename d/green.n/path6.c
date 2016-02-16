// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
这是一条平整的石板路, 上面隐约可以看见两道很深的车轮, 看来
是用来作运输用途的道路. 往西是通往山下的路, 往东你可以看到一些
建筑物, 像是村庄之类的. 南边看去是一片矮树丛.

LONG
	);
    set("exits", ([
    "west" : "/d/snow/crossroad",
    "east" : __DIR__"path5",
]));
	set("no_clean_up", 0);
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
