// Room: /d/choyin/tree_tomb.c

inherit ROOM;

void create()
{
	set("short", "树王坟");
	set("long", @LONG
你现在来到了著名的「树王坟」前，这里是个高台，中央约两丈见方
的地上有一截巨大的树桩，少说有三、四十人合抱那么粗，树桩中间有一
个大洞(hole)，望下去黑漆漆地，石台靠南的地方还有一间小庙(shrine)
，东西南北四个方向都有阶梯通往四面的街道。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"n_street3",
  "west" : __DIR__"w_street3",
  "south" : __DIR__"s_street3",
  "east" : __DIR__"e_street1",
]));
	set("item_desc", ([ /* sizeof() == 2 */
  "hole" : "一个黑漆漆的大洞，看来像是什么蛀虫蛀出来的，可是天底下哪里
有这么大的蛀虫？这个洞连人也进得去。
",
  "shrine" : "一间砖砌的小庙，庙里供奉的当然就是「树王公」，你注意到庙里
树王公的神像左手残缺不全，木刻的神像竟然有一条条白蚁的痕迹，和
一般庙里金身神像给人的印象不太一样。
",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
