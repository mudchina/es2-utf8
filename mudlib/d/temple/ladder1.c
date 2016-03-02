// Room: /d/temple/ladder1.c

inherit ROOM;

void create()
{
	set("short", "石英岩石阶");
	set("long", @LONG
长长的阶梯也终将到了尽头, 阶梯的尽头矗立著一座山门, 山门
上龙飞凤舞地写了三个字, 笔力苍劲有力显得气势非凡。山风吹来带
著丝丝的寒意, 令你有股高处不胜寒的感觉。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/little_taoist1" : 1,
]));
	set("outdoors", "temple");
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"entrance",
  "eastdown" : __DIR__"ladder2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
