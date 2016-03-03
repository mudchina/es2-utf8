// Room: /d/temple/ladder2.c

inherit ROOM;

void create()
{
	set("short", "石英岩石阶");
	set("long", @LONG
你正走在一道长长的石英岩阶梯上, 阶梯的两侧种植著一排高耸
的松树。抬头望望东北边那座高耸挺拔的山峰, 在云雾飘渺的山顶上
, 矗立著一座雄伟的白色楼阁。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guest" : 1,
]));
	set("outdoors", "temple");
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"ladder1",
  "southdown" : __DIR__"ladder3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
