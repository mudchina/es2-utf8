// Room: /d/choyin/s_street2.c

inherit ROOM;

void create()
{
	set("short", "福林大街");
	set("long", @LONG
这里是乔阴县城的福林大街，东首一栋雕梁画栋，美仑美奂的华厦
便是乔阴县最大的酒楼「福林楼」，不但乔阴县城的富商大贾常来此楼
饮宴，就连方圆百里内的许多豪门巨绅也常常到这里喝酒，西边是一条
宽敞的青石官道，通往县府衙门，街道往南则是热闹的南门广场。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"s_street3",
  "south" : __DIR__"s_street1",
  "east" : __DIR__"hotel1",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
