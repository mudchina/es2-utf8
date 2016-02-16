// Room: /d/choyin/hotel3.c

inherit ROOM;

void create()
{
	set("short", "福林酒楼");
	set("long", @LONG
这里是福林酒楼的客房，住的都是一些从外地来的富商大贾，为了
预防宵小盗窃财物，福林酒楼的汤掌柜特别雇请了许多武师担任守卫的
工作，往下可以回到二楼。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"down" : __DIR__"hotel2",
	]));
	set("objects", ([
		__DIR__"npc/guard": 3
	]) );

	setup();
	replace_program(ROOM);
}
