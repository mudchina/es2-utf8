// Room: /d/goathill/mroad4.c

inherit ROOM;

void create()
{
	set("short", "山路转角");
	set("long", @LONG
你现在正走在一条崎岖山路的转角处，山路望东通往野羊山上，从
这里可以望见东边不远处有一个石屋立在岩壁边上，看起来像是冈哨或
什么的，北边的山壁有一个裂口(crack)，不过离地约有三到四丈， 往
南的山路是段陡峭的下坡，如果你要下山，大概就是这条路了。
LONG
	);
	set("outdoors", "goathill");
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"mroad5",
		"southdown" : __DIR__"mroad3",
	]));
	set("objects", ([
		__DIR__"npc/bandit" : 3,
		__DIR__"npc/bandit_leader" : 1,
	]) );

	setup();
	replace_program(ROOM);
}
