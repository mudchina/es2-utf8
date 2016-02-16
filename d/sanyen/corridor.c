// Room: /d/sanyen/corridor.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
你正走在一条长廊上, 两旁种植著一排月桂树。南边的布幔后是
大殿, 北方则是后殿。东边是个不小的广场, 广场上正晒著一些不知
名的药草。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : "/d/sanyen/corridor1",
  "north" : "/d/sanyen/back_temple",
  "south" : "/d/sanyen/temple",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
