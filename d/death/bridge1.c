// Room: /d/death/bridge1.c

inherit ROOM;

void create()
{
	set("short", "奈何桥");
	set("long", @LONG
这里是一条漫长的石桥，往南石桥延伸进大雾之中，望不到尽头，
往北引隐约约有一座城楼，不过你分不清是真实的影像还是幻觉，东西
两面都是一望无际的大雾，一阵阵阴冷的微风从雾中吹过。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"bridge",
]));

	setup();
	replace_program(ROOM);
}
