// Room: /d/village/lakebottom2.c

inherit ROOM;

void create()
{
	set("short", "水下岩洞");
	set("long", @LONG
水下岩洞到了这里，突然变得非常宽阔，巨大的穹顶成半透明，能模
糊地看到顶外的小鱼游来游去。自上而下的看去，你不仅倒吸一口冷气：
几只白色的大龙或悬浮在空中、或盘在冰面上、或慢游在洞里的水潭中。
西面有一冰制的阶梯盘旋而上，不知伸向哪里。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"valley1",
  "eastdown" : __DIR__"lakebottom1",
]));
	set("objects", ([
		__DIR__"npc/dragon":6, 
	]) );
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
