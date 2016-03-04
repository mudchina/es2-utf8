// Room: /d/sanyen/tunnele.c

inherit ROOM;

void create()
{
	set("short", "隧道口");
	set("long", @LONG
你走进了一个凿穿山壁开成的隧道，东边是隧道的出口，往西不远
处也可以从这里瞧见西边的出口，一股硫磺的味道从隧道壁中传来，想
必左近便有温泉或是火山。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tunnel",
  "east" : __DIR__"gate",
]));

	setup();
	replace_program(ROOM);
}
