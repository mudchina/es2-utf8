// Room: /d/snow/herbshop.c

inherit ROOM;

void create()
{
	set("short", "桑邻药铺");
	set("long", @LONG
这里是一间规模不小的药铺，奇怪的是，在这里你闻不到一丝药铺
应有的药味，有的只是一股淡淡的檀香，令人觉得心旷神怡，药铺的柜
台就在店铺靠北的一面，柜台后是一个巨大的药柜(cabinet)， 上面的
小抽屉只怕有七、八百个之多，但是全部没有贴标签，药铺的出口在东
边，柜台上贴著一张发黄的纸片(sign)。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
		"cabinet" : @TEXT
一座巨大的杉木药柜，从它暗红色的纹理跟几处磨得发亮的痕迹，
这个药柜年代想必相当久远了，有一点很特殊的是，药柜和墙壁似乎贴
得非常紧密，看不出丝毫缝隙。
TEXT
		,
		"sign": "纸片上写著：价目表请用 list 向掌柜查询。\n",
]));
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"mstreet3",
	]));
	set("objects", ([
		__DIR__"npc/herbalist": 1,
		__DIR__"npc/woodcutter": 1,
	]) );

	setup();
	replace_program(ROOM);
}
