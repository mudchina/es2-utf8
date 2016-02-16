// Room: /u/k/karrimor/temple/corridor4.c

inherit ROOM;

void create()
{
	set("short", "回廊");
	set("long", @LONG
你正站在回廊转角的地方, 回廊从这往东边及南边而去。在北边
是一间大房子, 里面传来阵阵叱喝的声音。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
     "north" : __DIR__"trainroom",
     "south" : __DIR__"corridor6",
     "east" : __DIR__"corridor5",
]));

    create_door("north", "木门", "south");
	setup();
}
