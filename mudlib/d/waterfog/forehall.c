// Room: /d/waterfog/forehall.c

inherit ROOM;

void create()
{
	set("short", "聆啸厅");
	set("long", @LONG
这里是水烟阁二楼的聆啸厅，南面是一个大露台，按著西、西南、
南、东南、东等方向立著五块灰绿色的怪石(stone)，东西各有一个出
口通往侧厅，往北则是水烟阁主所居的春秋水色斋。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"west_2f",
		"east" : __DIR__"east_2f",
	]));
	set("objects", ([
		__DIR__"npc/elder5" : 1,
		__DIR__"npc/elder6" : 1,
		__DIR__"npc/elder7" : 1,
	]) );
	setup();
	replace_program(ROOM);
}
