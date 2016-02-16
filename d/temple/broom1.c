// Room: /d/temple/broom1.c

inherit ROOM;

void create()
{
    set("short", "经楼");
	set("long", @LONG
这里是灵心观中收藏书籍的地方, 四周的书架上堆了满满的书。
有些书已经旧的纸张都泛黄了, 摸一摸可能就会散掉甚至变成飞灰。
你再仔细的看了看, 发现这里都只是些寻常的修道的书籍, 似乎没有
什么特别的。角落里有一座小小的木梯通往二楼。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : "/d/temple/broom2",
  "out" : "/d/temple/road2",
]));

	setup();
	replace_program(ROOM);
}
