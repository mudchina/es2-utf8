// Room: /d/village/valley2.c

inherit ROOM;

void create()
{
	set("short", "忘情谷外");
	set("long", @LONG
这里是忘情谷外的一条小路，往东就进了名叫傅家坡的小村庄。从村
庄往外的这段小路人烟稀少，但能经常见到有大鸟飞过忘情谷的山岭。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"valley1",
  "east" : __DIR__"road6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
