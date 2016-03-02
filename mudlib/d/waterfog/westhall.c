// Room: /d/waterfog/westhall.c

inherit ROOM;

void create()
{
	set("short", "水烟阁西侧花厅");
	set("long", @LONG
这里是水烟阁入口西侧的花厅，东边是水烟阁的正门，南边和西边
围著一圈白玉栏杆，栏杆外种著许多茶花，往北是水烟阁的侧门，从这
里可以看到通往水烟阁二楼的阶梯。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"weststair",
		"east" : __DIR__"entrance",
]));

	setup();
	replace_program(ROOM);
}
