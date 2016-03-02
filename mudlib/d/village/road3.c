// Room: /d/village/road3.c

inherit ROOM;

void create()
{
	set("short", "青石小路");
	set("long", @LONG
这是一条通向一个村庄的青石小路。路口立着一个小牌子(tablet)，
牌子看起来经过长时间的日晒雨淋，已破烂不堪。东南向望去好像是片
瓜地，绿油油的西瓜让你感觉更渴了。从这里往西就进了村子，向东到
三叉路口。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road4",
  "east" : __DIR__"road2",
]));
	set("no_clean_up", 0);
	set("item_desc", ([
		"tablet":"你勉强分辨出那上面模糊的字迹：傅家坡\n"
	]) );
	setup();
	replace_program(ROOM);
}
