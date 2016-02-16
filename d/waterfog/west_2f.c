// Room: /d/waterfog/west_2f.c

inherit ROOM;

void create()
{
	set("short", "西侧厅");
	set("long", @LONG
这里是水烟阁西侧厅的二楼，由于侧厅是挑高建筑，因此这里只有
一条约七、八尺宽的走道连接楼梯与往东的门。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"down" : __DIR__"weststair",
		"east" : __DIR__"forehall",
	]));
	set("objects", ([
		__DIR__"npc/elite_guard": 2
	]) );

	set("waterfog_guard_dir", "east");
	setup();
	replace_program(ROOM);
}
