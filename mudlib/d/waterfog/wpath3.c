// Room: /d/waterfog/wpath3.c

inherit ROOM;

void create()
{
	set("short", "白石阶梯");
	set("long", @LONG
你正走在一道白石阶梯上，这道阶梯依著山壁而建，东边隔著一个
深不见底的山谷可以望见对面傲立在山巅之上的水烟阁，每当清晨山谷
中的晨雾慢慢飘起，从这里可以看见水烟阁彷佛飘在云间，这就是水烟
十景中的「飞天楼阁」，石阶沿著山壁从这里转往北方。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/waterfog/wpath4",
  "south" : "/d/waterfog/wpath2",
]));
	set("no_clean_up", 0);
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
