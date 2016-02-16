// Room: /d/goathill/mroad1.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你现在正走在一条崎岖的山路上，凹凹凸凸的山石刺得你的脚底隐
隐生疼，山路往南不远处通往一个山腰的台地，这一带最大的镇甸就位
在台地上，东边跟西边都是陡峭的山壁，山路往北通往层层叠叠的群山
之中。
LONG
	);
	set("outdoors", "goathill");
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"mroad2",
		"south" : "/d/snow/crossroad",
]));

	setup();
	replace_program(ROOM);
}
