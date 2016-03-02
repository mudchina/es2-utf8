// Room: /d/oldpine/cliffside.c

inherit ROOM;

void create()
{
	set("short", "林间....不....悬崖边");
	set("long", @LONG
你现在正站在一个松树林间的小空地上，你的北边、东边、南边都
是茂密的松树，唯独西边是个悬崖(cliff)，当你探头一看，立刻不由
自主地倒抽一口凉气，在这里可得千万小心，一不小心跌了下去肯定是
粉身碎骨。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
///  "south" : "/d/oldpine/pine2",
  "north" : "/d/oldpine/pine1",
///  "east" : "/d/oldpine/pine1",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "cliff" : "你定下心神一看，其实这个悬崖没有想像中那么恐怖，也许\还
可以从这里爬下山涧，只是这世界上大概没有这种白痴愿意干
这种傻事吧。
",
]));
	set("outdoors", "oldpine");

	setup();
	replace_program(ROOM);
}
