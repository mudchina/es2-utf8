// Room: /d/village/valley1.c

inherit ROOM;

void create()
{
	set("short", "忘情谷外");
	set("long", @LONG
这里是忘情谷外的一条小路，向着南和北延伸。山岭上树木繁茂，绿
草茵茵，东面是有名的玉螺湖，湖上水汽蒸腾，但这边岸上没有船，不能
由此到湖上。隐隐约约地看的见错落有致的村庄农舍。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"valley2",
  "eastdown" : __DIR__"lakebottom2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
