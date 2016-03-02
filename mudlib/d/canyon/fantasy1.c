// Room: /d/canyon/fantasy1.c

inherit ROOM;

void create()
{
	set("short", "梦幻迷境通道");
	set("long", @LONG
来到镜内，前面呈现三面通道，各个通道皆有其不同的气氛传出
，中道有浓厚的竹之气息，上道迷香之味不止，下道呕味不停，不定
的上空，不停蠢地之幻地，空气被抽丝剥茧，呼吸也愈来愈困难，不
停变动的景象，快决定吧!!暗中之招唤，心中为之一震，快步踏离此
一不祥的空间。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"up" : __DIR__"dream/tmp",
		"down" : __DIR__"evil/tmp",
		"back" : __DIR__"stone_forest3",
		"center" : __DIR__"bamboo/bamboo1",
]));

	setup();
	replace_program(ROOM);
}
