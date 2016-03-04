inherit ROOM;

void create()
{
   set("short", "晚月庄后门");
	set("long", @LONG
这是晚月庄的后门，在美丽的湘园南侧，这有一个木制的小门。
走出门外应是通往天山的小径。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "north" :__DIR__"paroad1",
    "south" :"/d/latemoon/sroad1",
]));

	setup();
	replace_program(ROOM);
}
