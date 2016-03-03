// Room: /u/k/karrimor/temple/sroad.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
这是一条宽敞坚实的青石大道, 大道沿著山腰往南向山下延伸, 东
边是一条石英岩石阶蜿蜒往山上而去。在石阶的尽头, 是一座颇为雄伟
的道观, 在江湖跑过的人都知道, 那是茅山派的所在地。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "eastup" : __DIR__"ladder5",
     "south"   : "/d/snow/eroad3",
]));
	set("outdoors", "temple");

	setup();
	replace_program(ROOM);
}
