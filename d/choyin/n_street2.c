// Room: /d/choyin/n_street2.c

inherit ROOM;

void create()
{
	set("short", "福林大街");
	set("long", @LONG
你现在正走在一条宽敞的街道上，这里是乔阴县联通南北城门的福
林大街，街道从这里向南北延伸，往北远远地可以望见北门的石牌楼，
南边不远处则是乔阴县城著名的地标「树王坟」，你的东边有一家三层
楼的酒馆，西边则是远近驰名的老姚布庄，街上不时有贩夫走卒穿梭
而过，十分热闹。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"n_street3",
  "north" : __DIR__"n_street1",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
