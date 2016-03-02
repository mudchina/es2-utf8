// Room: /d/snow/smithy.c

inherit ROOM;

void create()
{
	set("short", "打铁铺子");
	set("long", @LONG
这里是一间打铁铺子，从火炉中冒出的火光将墙壁映得通红，屋子
的角落里堆满了各式铁器的完成品或未完成品，像是锄头、铁锤、铲子
等，叮叮当当的声音敲得满屋子响。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : "/d/snow/mstreet2",
]));

	set("objects", ([
		"/d/snow/npc/smith": 1 ]) );
	setup();
	replace_program(ROOM);
}
