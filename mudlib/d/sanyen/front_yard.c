// Room: /d/sanyen/front_yard.c

inherit ROOM;

void create()
{
	set("short", "山烟寺前广场");
	set("long", @LONG
这里是山烟寺前的空地，平日僧人们就在这里练武强身，空地四周
种了一排白杨树，靠北边的地方放了一堆用来锻链膂力的砖头，寺门就
在你的北边, 西边则是山门。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/sanyen/door",
  "west" : "/d/sanyen/gate",
]));
	set("outdoors", "sanyen");
        set("objects", ([
                "/u/cloud/npc/monk_guard":2,
        ]) );

	setup();
	replace_program(ROOM);
}
