// Room: /d/waterfog/wpath1.c

inherit ROOM;

void create()
{
	set("short", "山坡小径");
	set("long", @LONG
你现在正走在一条山坡上的小径，往南望去只见山下一条白色石阶
蜿蜒上山，通往东边不远处的一个平台，平台的北边就是赫赫有名的武
者圣地「水烟阁」，小径的北边整齐地种著一排枫树，往西上了山坡通
往位于山巅的「虹台」。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/waterfog/wpath2",
  "east" : "/d/waterfog/frontyard",
]));
	set("no_clean_up", 0);
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
