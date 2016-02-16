// Room: /d/choyin/e_street1.c

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
    这里是乔阴县城的东大街，西边不远处的石台便是远近驰名的「树
王坟」，东大街往东一直通往东城门，街道两边有许多的民宅，街上行
人渐稀。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tree_tomb",
  "east" : __DIR__"e_gate",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
