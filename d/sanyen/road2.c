// Room: /d/sanyen/road2.c

inherit ROOM;

void create()
{
	set("short", "石板小径");
	set("long", @LONG
你正走在一条青石板铺造的小径上, 两旁种植著一排芍药。阵阵
药香随风送了过来, 原来东边是片广大的药圃。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/sanyen/road1",
  "east" : "/d/sanyen/drag_field",
]));
	set("objects", ([
		__DIR__"npc/bonze":1 ]) );
	set("outdoors", "sanyen");

	setup();
	replace_program(ROOM);
}
