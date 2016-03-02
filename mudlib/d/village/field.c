// Room: /d/village/field.c

inherit ROOM;

void create()
{
	set("short", "稻田");
	set("long", @LONG
这是一片绿油油的稻田，稻子的长势非常喜人，因为北面就是玉螺湖，
所以稻田的灌溉很方便。从这儿向西能看到忘情谷那郁郁葱葱的山岭，东
面能看到几间高大房屋高出柳树部分的屋檐。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"road9",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
