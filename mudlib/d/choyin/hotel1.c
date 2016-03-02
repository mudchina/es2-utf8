// Room: /d/choyin/hotel1.c

inherit ROOM;

void create()
{
	set("short", "福林酒楼");
	set("long", @LONG
这里便是乔阴县驰名远近的福林酒楼，连乔阴县最热闹的一条大街
都以此命名，福林酒楼是一家近百年老店，传到现在的这位掌柜已经是
第三代，如果你是初到此地的外地人，不妨和他攀攀交情，酒楼一楼多
半是县城里熟客人，东北边有一道方梯通往楼上雅座，往西则可以出大
街。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"up" : __DIR__"hotel2",
		"west" : __DIR__"s_street2",
	]));
	set("objects", ([
		__DIR__"npc/boss" : 1,
		__DIR__"npc/sergeant" : 1,
	]) );

	setup();
	replace_program(ROOM);
}
