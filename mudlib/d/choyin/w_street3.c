// Room: /d/choyin/w_street3.c

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
这里是乔阴县城的西大街，东边不远处的石台便是远近驰名的「树
王坟」，西大街往西一直通往西城门，街道两边有许多的商店，街上人
来人往好不热闹。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"nw_street",
  "west" : __DIR__"w_street2",
  "east" : __DIR__"tree_tomb",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
