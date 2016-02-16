// Room: /d/village/melonguard.c

inherit ROOM;

void create()
{
	set("short", "瓜棚");
	set("long", @LONG
这是一间茅草铺顶，竹竿作架的棚子，平时瓜农就在这里看着瓜地，
他们的警惕性都很高，稍有风吹草动都会警觉起来。瓜地在瓜棚的北面，
往西北走就上了村里的小路，往南能看到地主田老财的宅院。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"melonfarm",
  "northwest" : __DIR__"road7",
]));
	set("objects",([
		__DIR__"npc/meloner":3,
	]) );
	
	set("no_clean_up", 0);

	setup();
}
