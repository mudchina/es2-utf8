// Room: /d/oldpine/tree1.c

inherit ROOM;

void create()
{
	set("short", "大松树上");
	set("long", @LONG
你现在正攀附在一株大松树的树干上，从这里可以很清楚地望见树
下的一切动静，而不被人发觉，似乎是个干偷鸡摸狗勾当的好地方。
LONG
	);
	set("objects", ([
		"/d/oldpine/npc/spy":1 ]) );

	set("exits", ([ /* sizeof() == 2 */
  "up" : "/d/oldpine/tree2",
  "down" : "/d/oldpine/clearing",
]));

	setup();
	replace_program(ROOM);
}
