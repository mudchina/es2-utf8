// Room: /d/choyin/hotel2.c

inherit ROOM;

void create()
{
	set("short", "福林酒楼");
	set("long", @LONG
这里是福林酒楼的二楼雅座，这里的客人大多衣冠鲜明，若不是富
豪巨绅，便是秀才举人，使你不知不觉跟著斯文起来，从这里可以眺望
乔阴县城的市景，东边不远处隔著几栋建筑便是县府衙门，南边是碧波
荡漾的翠柳湖，湖对岸的雨桥庄在柳树间若隐若现，东边许多民房，再
过去便是一方方的稻田，北边可望见树王坟的石台，以及乔阴县城北的
建筑。你可以沿角落的方梯回到一楼，或者到三楼的客房。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"up" : __DIR__"hotel3",
		"down" : __DIR__"hotel1",
	]));
	set("objects", ([
		__DIR__"npc/youngman": 1,
		__DIR__"npc/servant": 3
	]) );

	setup();
	replace_program(ROOM);
}
