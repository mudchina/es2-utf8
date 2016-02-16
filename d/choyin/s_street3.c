// Room: /d/choyin/s_street3.c

inherit ROOM;

void create()
{
	set("short", "福林大街");
	set("long", @LONG
这里是乔阴县城的福林大街，往北是一座高台，台上便是著名的「
树王坟」，打从这里往南就是乔阴县最热闹的街道，接上来往的行商贩
子也最多，你的东边和西边都是石板空地，平常的市集便在此处，遇到
赛会节庆这里更是挤得水泄不通，福林大街往南是个路口。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"s_street2",
  "north" : __DIR__"tree_tomb",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
