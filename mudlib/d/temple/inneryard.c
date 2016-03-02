// Room: /u/k/karrimor/temple/inneryard.c

inherit ROOM;

void create()
{
	set("short", "天井");
	set("long", @LONG
你正站在灵心观的天井里, 这里种植著一些花草树木, 在西北角
落里有著一口水井。北边就是供俸茅山派历代掌门人的地方, 南边则
是一面墙, 墙的另一侧就是大殿。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
     "north" : __DIR__"corridor5",
     "west" : __DIR__"corridor6",
     "east" : __DIR__"corridor7",
]));

    set("objects", ([ /* sizeof() == 1 */
        __DIR__"npc/little_taoist2" : 1,
    ]) );
	set("outdoors", "temple");

	setup();
	replace_program(ROOM);
}
