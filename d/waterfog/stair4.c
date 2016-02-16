// Room: /d/waterfog/stair4.c

inherit ROOM;

void create()
{
	set("short", "白石阶梯");
	set("long", @LONG
你现在正走在一条长长的白石阶梯上，这些建造阶梯的白石出产于
东海滨的裂瓶山，距离此地有近千里之遥，而且虽然年代久远，仍然可
以看得出所用的全部都是品质最好的「拟玉」石，可见这里的主人必定
大有来头。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : "/d/waterfog/clifftop",
  "southdown" : "/d/waterfog/stair3",
]));
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
