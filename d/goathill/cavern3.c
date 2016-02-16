// Room: /d/goathill/cavern3.c

inherit ROOM;

void create()
{
	set("short", "岩穴");
	set("long", @LONG
这里一片黑漆漆，你必须全靠摸索才能不至于撞到岩壁，你听到东
边传来阵阵滴水的声音，可是伸手一摸却仍是冷冰冰、又乾又硬的岩石
，地上布满了许多又黏又稠的不知名东西，使你每一步都走得异常艰辛
。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"cavern2",
	]));
	set("objects", ([
		__DIR__"npc/big_worm": 2,
		__DIR__"npc/huge_worm": 2,
	]) );

	setup();
	replace_program(ROOM);
}
