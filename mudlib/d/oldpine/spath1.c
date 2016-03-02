// Room: /d/oldpine/spath1.c

inherit ROOM;

void create()
{
	set("short", "林间小路");
	set("long", @LONG
你现在正走在一片松树林中的小路上，小路往北通往一处空地，一
株巨大无朋的松树矗立在空地中央，小路往南是一条长长的下坡道，这
条路上足迹很多，显然常有人经过。
LONG
	);
	set("objects", ([ /* sizeof() == 3 */
//  __DIR__"npc/tall_bandit" : 1,
//  __DIR__"npc/fat_bandit" : 1,
  __DIR__"npc/bandit" : 3,
]));
	set("outdoors", "oldpine");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"clearing",
  "north" : __DIR__"spath2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
