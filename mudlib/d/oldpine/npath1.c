// Room: /d/oldpine/npath1.c

inherit ROOM;

void create()
{
	set("short", "林间小路");
	set("long", @LONG
你现在正走在一条林间的小路，往北不远处走出这座林子就是雪亭
镇，小路两旁长满了许多高耸的松树，雪亭镇的居民都把这里叫做「老
松林」，据说林子里有株树龄上千的老松树，颇有灵验。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"npath2",
  "northwest" : "/d/snow/eroad3",
]));
	set("outdoors", "oldpine");

	setup();
	replace_program(ROOM);
}
