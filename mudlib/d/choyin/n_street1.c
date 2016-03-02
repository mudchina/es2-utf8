// Room: /d/choyin/n_street1.c

inherit ROOM;

void create()
{
	set("short", "福林大街");
	set("long", @LONG
你现在正走在一条宽敞的街道上，这里是乔阴县城联通北门与南
门的福林大街，街道两旁有做生意的，有做粗活的，这里的老百姓大多
是老老实实的农人与工匠，街上卖的也多半是一些日用品，往东边是一
条小巷子，南边的街道似乎比较热闹一些，北边则是北门。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"n_street2",
  "north" : __DIR__"n_gate",
]));
	set("objects", ([
		__DIR__"npc/cake_vendor": 1,
		CLASS_D("beggar") + "/master": 1
	]) );
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
