// Room: /d/oldpine/epath1.c

inherit ROOM;

void create()
{
	set("short", "林间小路");
	set("long", @LONG
你现在正走在一条松树林中的小路，这里的松树树干上都有著一些
奇怪的记号，像是被人用刀子划过，小路的西边是一块空地，往东不远
可以看到一条山涧，上面横跨著一座小石桥。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/oldpine/clearing",
  "east" : "/d/oldpine/epath2",
]));
	set("outdoors", "oldpine");

	setup();
	replace_program(ROOM);
}
