// Room: /d/canyon/canyon6.c

inherit ROOM;

void create()
{
	set("short", "天驼关谷地");
	set("long", @LONG
高耸的悬崖立在天驼关两侧，中间是并不开阔的谷地，真是易守难
攻的好地方，这么多年来与异族的关系一直非常缓和，因此大门又重新
打开。铁门的后面有个很大的机械装置(machine)，向南是通往京城的
路，往北就出了天驼关。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"canyon7",
  "north" : __DIR__"canyon5",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "mechine" : "这是个很大的绞盘，可能是开关铁门用的。\n",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
