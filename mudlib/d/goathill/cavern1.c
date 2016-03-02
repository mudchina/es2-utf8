// Room: /d/goathill/cavern1.c

inherit ROOM;

void create()
{
	set("short", "岩洞");
	set("long", @LONG
这个岩洞的内部似乎远比你想像得大，岩壁上有一条条的深沟彷佛
是被什么蛀虫给蛀出来的，可是有什么虫会去啃咬这又硬又厚的岩壁呢
？洞穴的出口在你的西边透著微光，东北边跟西北边各有一个洞穴，黑
暗中似乎有什么东西在蠕蠕而动。
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/worm" : 2,
]));
	set("exits", ([ /* sizeof() == 3 */
		"southeast" : __DIR__"cavern4",
		"northeast" : __DIR__"cavern2",
		"west" : __DIR__"canyon3",
]));

	setup();
	replace_program(ROOM);
}
