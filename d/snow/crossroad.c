// Room: /d/snow/crossroad.c

inherit ROOM;

void create()
{
	set("short", "山坳");
	set("long", @LONG
这里是一处山坳，往南就是雪亭镇，一条蜿蜒的小径往东通往另一
个邻近的小山村，一块官府立的告示牌立在路旁，上面写著有关野羊山
土匪出没的警告标志。
LONG
	);
	set("outdoors", "snow");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
		"north" : "/d/goathill/mroad1",
		"east" : "/d/green/path6",
		"south" : __DIR__"mstreet4",
]));

	setup();
	replace_program(ROOM);
}
