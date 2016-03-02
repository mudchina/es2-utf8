// Room: /d/temple/ladder3.c

inherit ROOM;

void create()
{
	set("short", "石英岩石阶");
	set("long", @LONG
你正走在一道长长的石英岩阶梯上, 阶梯的两侧种植著一排高耸
的松树。雪亭镇就在东边不远的山下, 你隐约还能听到从镇上传来的
话语声。阶梯从这里弯向南边。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"ladder2",
  "eastdown" : __DIR__"ladder4",
]));
	set("no_clean_up", 0);
	set("outdoors", "temple");

	setup();
	replace_program(ROOM);
}
