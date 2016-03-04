// Room: /d/waterfog/wpath4.c

inherit ROOM;

void create()
{
	set("short", "白石阶梯");
	set("long", @LONG
你现在正走在一道依著山壁而建的白石阶梯上，随著阶梯越爬越高
，从这里已经可以望见西面山顶上竖立在虹台中央的「擎天柱」，阶梯
从这里转向西北坡度较缓的山腰，你的东边是一个深不见底的深谷，隔
著深谷可以望见对面不远处的水烟阁。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/waterfog/wpath3",
  "north" : "/d/waterfog/wpath5",
]));
	set("no_clean_up", 0);
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
