// Room: /d/waterfog/wpath2.c

inherit ROOM;

void create()
{
	set("short", "山坡小径");
	set("long", @LONG
你现在正走在一条山坡小径上，东边不远处可以望见水烟阁琉璃色
的屋瓦，小径东北是一道白石阶梯通往山巅的虹台，往西则是「水烟十
景」之中最有名的虹谷断崖，小径旁立著一个七、八尺高的石碑(stone
)。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : "/d/waterfog/wpath3",
  "east" : "/d/waterfog/wpath1",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "stone" : "石碑上面几个苍劲古朴的字写道：虹谷石台，乙丑年水烟阁第六代
阁主关雨楼立。
你仔细一看，这几个字迹丝毫没有斧凿痕迹，竟像是题字的人直接
用手指在岩石上写出来一般。
",
]));
	set("no_clean_up", 0);
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
