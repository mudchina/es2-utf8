// Room: /u/cloud/m_house.c

inherit ROOM;

void create()
{
	set("short", "张百万家");
	set("long", @LONG
这里是张百万的府宅，常人可进不来
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"rich",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/millinare" : 1,
  __DIR__"npc/jiading" : 2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
