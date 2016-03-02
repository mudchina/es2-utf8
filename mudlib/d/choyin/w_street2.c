// Room: /d/choyin/w_street2.c

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
这里是乔阴县城的西大街，西门就在你的西边几十丈外，望东则是
通往乔阴县的著名地标「树王坟」，街上有许多商店，北边是一家大酒
楼，南边则有一间染坊。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"w_street1",
  "east" : __DIR__"w_street3",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
