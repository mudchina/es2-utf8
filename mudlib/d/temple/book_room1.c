// Room: /d/temple/book_room1.c

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
  "up" : __DIR__"book_room2",
  "out" : __DIR__"road2",
]));
	set("no_clean_up", 0);

	setup();
}

int valid_leave(object me,string dir)
{
     if ( dir=="out" )
          {
           message_vision("\n$N拉开门大步走了出去, 随手把门带上。\n\n", this_player());
           tell_room(__DIR__"road2", "你看到藏经楼的门从里打开, 有人走了出来并顺手把门带上。\n\n");
           ::valid_leave(me, dir); 
          }
     return 1;
}
