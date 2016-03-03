// Room: /d/waterfog/sroad1.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
这是一条宽敞坚实的青石板大道，从这里已经可以望见北边山腰上
水烟阁琉璃色的屋瓦，映著山上茂密的枫树林，显得十分诗情画意，由
于这条路是禁兵统领亲自督造，因此造得格外平整，从这里开始已经进
入由历代水烟阁主人所管辖的封地，即使是官府也不能过问这片土地上
发生的事，因此你最好小心一点。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : "/d/snow/sroad4",
  "northwest" : "/d/waterfog/sroad2",
]));
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
