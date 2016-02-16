// Room: /d/oldpine/keep3.c

inherit ROOM;

void create()
{
	set("short", "老松寨");
	set("long", @LONG
这里就是老松寨的大厅了，靠北边的地面上铺了一张巨大的熊皮，
上面摆了三张椅子，大厅四周散落著几个取暖用的火盆，几个上了锁的
木箱子，比较奇特的是中央掘了一个大坑(pool)，坑里是许多头骨浸在
一种发著恶臭的黄水之中。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"keep2",
	]));
	set("objects", ([
		__DIR__"npc/bandit_leader": 3,
		__DIR__"npc/bandit_commander":1
	]) );

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
