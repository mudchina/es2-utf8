// Room: /d/goathill/cavern4.c

inherit ROOM;

void create()
{
	set("short", "岩洞");
	set("long", @LONG
这里是一处阴暗的岩洞，等你走近这个岩洞才发现原来是死路，东
北边隐隐透出几道微光，想必是洞穴的出口，地上一滩滩暗黄色的黏稠
物不知道士什么东西，闻起来竟一点味道也没有。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"northwest" : __DIR__"cavern1",
	]));
	set("objects", ([
		__DIR__"npc/worm": 2,
		__DIR__"npc/big_worm": 1
	]) );

	setup();
	replace_program(ROOM);
}
