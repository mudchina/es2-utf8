// Room: /d/waterfog/eaststair.c

inherit ROOM;

void create()
{
	set("short", "东侧厅");
	set("long", @LONG
这里是水烟阁东边的侧厅，东边隔著栏杆就是深不见底的深谷，从
这里向外眺望，更可以感受到水烟阁孤立于独峰之上，傲视群山的气魄
，这里有一道阶梯通往二楼，往北是厨房与储存杂物的仓库。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"up" : __DIR__"east_2f",
		"south" : __DIR__"easthall",
		"north" : __DIR__"kitchen",
]));

	setup();
	replace_program(ROOM);
}
