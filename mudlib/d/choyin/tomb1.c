// Room: /d/choyin/tomb1.c

inherit ROOM;

void create()
{
	set("short", "树王坟");
	set("long", @LONG
这里是树王坟内部的树洞，由于这棵大树实在太大，因此你站在树
洞里，一点也不觉得局促，树洞约有两个人的高度那么深，你可以攀附
粗糙的洞壁往上离开，东边的树根比较少，露出一些土层，北边跟西边
则是树洞的另一端。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"tomb3",
  "west" : __DIR__"tomb2",
  "up" : __DIR__"tree_tomb",
]));
	set("objects", ([
		__DIR__"npc/shadow": 3
	]) );

	setup();
	replace_program(ROOM);
}
