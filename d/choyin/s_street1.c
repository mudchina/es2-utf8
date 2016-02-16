// Room: /d/choyin/s_street1.c

inherit ROOM;

void create()
{
	set("short", "南门广场");
	set("long", @LONG
这里便是乔阴县城最大的一处广场，往北是贯通县城南北门的福林
大道，往东则是一个绿柳环绕的湖泊「翠柳湖」，广场上只见卖艺的，
卖糖葫芦的，捏面人的，各色小贩穿梭来去，广场中央有一口大井，井
旁用绳索绑著几只杯子供人取水喝(drink)，南门的牌楼因为几年前改建
翠柳湖的曲桥，因此移到西边的县府衙门所在的昌平街，现在广场的南
面就是一座曲桥通往湖东岸的雨桥庄，西南边一条宽敞的街道沿著湖岸
通往城外，广场的西边则一直延伸到昌平街。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"bridge1",
		"north" : __DIR__"s_street2",
		"west"	: __DIR__"s_street4",
		"southwest" : __DIR__"sw_road1",
	]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/cucurbit_seller" : 1,
		__DIR__"npc/dumpling_seller" : 1,
	]));
	set("resource/water", 1);
	set("outdoors", "choyin");
	setup();
}

void init()
{
	add_action("do_drink", "drink");
}

int do_drink(string arg)
{
	if( (int)this_player()->query("water") >=
		(int)this_player()->max_water_capacity() )
		return notify_fail("你已经再也喝不下一滴水了。\n");
	message_vision("$N在井边用杯子舀起井水喝了几口。\n", this_player());
	this_player()->add("water", 20);
	return 1;
}
