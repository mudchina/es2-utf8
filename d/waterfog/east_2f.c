// Room: /d/waterfog/east_2f.c

inherit ROOM;

void create()
{
	set("short", "东侧厅");
	set("long", @LONG
这里是水烟阁东侧厅的二楼，由于侧厅是挑高建筑，因此这里只有
一条约七、八尺宽的走道连接楼梯与往西的门。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"forehall",
		"down" : __DIR__"eaststair",
	]));
	set("objects", ([
		__DIR__"npc/elite_guard": 2
	]) );

	set("waterfog_guard_dir", "west");
	setup();
	replace_program(ROOM);
}
