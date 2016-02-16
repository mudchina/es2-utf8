// Room: /d/ice/cave0.c

inherit ROOM;

void create()
{
	set("short", "洞口");
	set("long", @LONG
一个狭窄的山洞, 西方的洞口被一些不知名的植物给遮住了一大半,
外面的光线由隙缝中照进来, 阵阵寒风也随之而入. 几根滴著水的冰柱
悬在洞顶, 水滴在地上形成一个个的凹洞. 往东是一个约一人高的通道
黑黝黝的不知通往何处.
 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : "/d/mine/cave0",
		"west" : __DIR__"path0",
]));

	setup();
	replace_program(ROOM);
}
