// Room: /d/waterfog/easthall.c

inherit ROOM;

void create()
{
	set("short", "水烟阁东侧花厅");
	set("long", @LONG
这里是水烟阁正门东边的花厅，东边和南边围著一圈白石栏杆，栏
杆外种著许多茶花，往西是水烟阁的正门，往北则是东侧的侧厅，从这
里可以看见通往二楼的阶梯。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"eaststair",
		"west" : __DIR__"entrance",
]));

	setup();
	replace_program(ROOM);
}
