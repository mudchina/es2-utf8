// Room: /u/cloud/rich.c

inherit ROOM;

void create()
{
	set("short", "张百万家");
	set("long", @LONG
你现在正站在张百万家里
    靠近门口的地方有一块乌木雕成的招牌(sign)。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"m_house",
  "south" : __DIR__"eroad3",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/room_gua" : 5,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
