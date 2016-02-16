// Room: /d/waterfog/frontyard.c

inherit ROOM;

void create()
{
	set("short", "水烟阁前");
	set("long", @LONG
你现在正站在一座高大的楼阁，水烟阁前，琉璃色的屋瓦和白玉般
的白石砖使得水烟阁在崇山峻岭中显得十分抢眼，这座楼阁最早的主人
据说是有「武术之神」称号的太阳神君「杞庸」，后来被当作历代武林
盟主的居所，可说是学武之人的朝圣地，一条白石阶梯沿著山腰往南而
下，水烟阁的大门就在你的北方。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : "/d/waterfog/wpath1",
  "north" : "/d/waterfog/entrance",
  "southdown" : "/d/waterfog/stair5",
]));
	set("no_clean_up", 0);
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
