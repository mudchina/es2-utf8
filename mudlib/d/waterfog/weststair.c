// Room: /d/waterfog/weststair.c

inherit ROOM;

void create()
{
	set("short", "西侧厅");
	set("long", @LONG
这里是水烟阁西侧的厅院，一道白石梯从这里通往二楼，往北是仆
役的卧房跟柴房，南边是出水烟阁的侧门，往西则是一个可以眺望山谷
的阳台。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"up" : __DIR__"west_2f",
		"north" : __DIR__"storage",
		"south" : __DIR__"westhall",
]));

	setup();
	replace_program(ROOM);
}
