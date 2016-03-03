// Room: /d/temple/ladder4.c

inherit ROOM;

void create()
{
	set("short", "石英岩石阶");
	set("long", @LONG
你正走在一道长长的石英岩阶梯上, 阶梯的两侧种植著一排高耸
的松树。雪亭镇就在西边不远的山下, 你隐约还能听到从镇上传来的
话语声。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"ladder3",
  "southdown" : __DIR__"ladder5",
]));
	set("no_clean_up", 0);
	set("outdoors", "temple");

	setup();
	replace_program(ROOM);
}
