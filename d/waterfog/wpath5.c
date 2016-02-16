// Room: /d/waterfog/wpath5.c

inherit ROOM;

void create()
{
	set("short", "白石阶梯");
	set("long", @LONG
你现在走在一道依著山壁而建的白石阶梯上，通过西边不远处的葬
剑亭，就是虹台的入口，东边和北边都是深不见底的深谷，隔著深谷，
东北边的野羊山连著隐樵山、图云岭、破魔山、虎啸坡、沙牢山一直到
大漠都是数百丈的高山，虹台地势虽不甚高，但是在三面深谷的环绕下
，却自有一股群山朝拜的威严气象。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/d/waterfog/wpath4",
  "west" : "/d/waterfog/swordtomb",
]));
	set("no_clean_up", 0);
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
