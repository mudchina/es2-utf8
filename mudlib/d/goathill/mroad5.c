// Room: /d/goathill/mroad5.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这里是一段狭窄的山路，往东不远处的岩壁边上有一座石屋，路旁
生满了及腰的长草，山风吹过一起一伏的有如波浪一般，南北两边有许
多大石，看起来倒是个埋伏的好地点，往西是一个山路的转角。
LONG
	);
	set("outdoors", "goathill");
	set("exits", ([ /* sizeof() == 3 */
		"northeast" : __DIR__"mroad6",
		"east" : __DIR__"slope1",
		"west" : __DIR__"mroad4",
]));

	setup();
	replace_program(ROOM);
}
