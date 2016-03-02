// Room: /d/snow/hockshop2.c

inherit ROOM;

void create()
{
	set("short", "储藏室");
	set("long", @LONG
这里是丰登当铺的储藏室，有时候当铺里的大朝奉会把铺里存不下
的死当货物拿出来拍卖，不过你现在只能看见一个个锁著的箱子。往西
边穿过一道布帘可以回到当铺店面。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : "/d/snow/hockshop",
]));

	setup();
	replace_program(ROOM);
}
