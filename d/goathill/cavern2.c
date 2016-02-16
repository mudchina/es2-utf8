// Room: /d/goathill/cavern2.c

inherit ROOM;

void create()
{
	set("short", "岩洞");
	set("long", @LONG
你现在正在一个黑漆漆的岩洞中摸索前进，西南边隐隐有些光亮，
想必是洞穴的出口，东边似乎有些滴水的声音，不过你得走过去才能听
得仔细，你感觉脚边有一些东西在蠕蠕而动，举脚又有些黏黏的，一阵
恶心的感觉压迫著你的胃。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"cavern3",
		"southwest" : __DIR__"cavern1",
	]));
	set("objects", ([
		__DIR__"npc/fat_worm" : 1,
		__DIR__"npc/worm" : 3,
	]) );

	setup();
	replace_program(ROOM);
}
