// Room: /d/temple/corridor3.c

inherit ROOM;

void create()
{
	set("short", "回廊");
	set("long", @LONG
你正站在回廊转角的地方, 回廊从这往西及南边而去。在走廊
的东侧是一排厢房。北方是一条铺著青石板的小径。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"road1",
		"south" : __DIR__"corridor7",
		"west" : __DIR__"corridor5",
		"east" : __DIR__"restroom2",
]));

        create_door("east","木门","west");

	setup();
}
