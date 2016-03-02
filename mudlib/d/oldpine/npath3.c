// Room: /d/oldpine/npath3.c

inherit ROOM;

void create()
{
	set("short", "林间小路");
	set("long", @LONG
你现在正走在一条林间的小路上，小路往东似乎通往一处空地，林
子到了这里变得静悄悄的，小路两旁的松树也比西边的矮小，看起来有
点营养不良的样子。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : "/d/oldpine/clearing",
  "northwest" : "/d/oldpine/npath2",
]));
	set("outdoors", "oldpine");

	setup();
	replace_program(ROOM);
}
