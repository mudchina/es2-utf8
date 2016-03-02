// Room: /d/canyon/stone_forest3.c

inherit ROOM;

void create()
{
	set("short", "梦幻迷境入口");
	set("long", @LONG
天光点著，华光亮，大概就是这样的一个情形吧，穿过了黄石穿
林路，一束极大的光注猛然照射到你的身上，犹如沐于春风，心情爽
朗极了，但面对北侧奇特的镜子居然有种令人不可抗拒的压力，在这
尺尺地方，镜面反射日光，强照黄石穿林路，想到这让你有种莫名的
恐惧，在莫名中被吸引而来的恐惧，进入或离开，生死一瞬间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"mirror" : __DIR__"fantasy1",
		"east" : __DIR__"stone_forest2",
]));

	setup();
	replace_program(ROOM);
}
