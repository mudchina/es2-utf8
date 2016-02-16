// Room: /d/choyin/n_street3.c

inherit ROOM;

void create()
{
	set("short", "福林大街");
	set("long", @LONG
你现在正走在一条宽敞的大街上，街道往北边笔直地延伸，南边则
是一个隆起的石台，你可以看见石台前有块石碑，上书「树王坟」三个
大字，街道的东边和西边都是石板空地，围绕著树王坟成为一个圆环，
许多小贩客商都聚集在这里交易买卖。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"nw_street",
  "north" : __DIR__"n_street2",
  "south" : __DIR__"tree_tomb",
]));
	set("objects", ([
		__DIR__"npc/dumpling_seller": 1
	]) );
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
