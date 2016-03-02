// Room: /d/snow/eroad1.c

inherit ROOM;

void create()
{
	set("short", "黄土小径");
	set("long", @LONG
这是一条普通的黄土小径，弯弯曲曲往东北一路盘旋上山，北边有
一间城隍庙，往西则是雪亭镇的街道。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : "/d/snow/eroad2",
  "north" : "/d/snow/temple",
  "west" : "/d/snow/sroad1",
]));
	set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}
