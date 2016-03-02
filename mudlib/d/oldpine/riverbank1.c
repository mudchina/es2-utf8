// Room: /d/oldpine/riverbank1.c

inherit ROOM;

void create()
{
	set("short", "山涧之中");
	set("long", @LONG
你现在正站在一条山涧中的岩石上，几股泉水正从你脚边流过，水
花溅得四处飞散，南边是一个深不见底的水潭(lake)，两边的山壁看起
来又高又陡，看来要爬上岸边实在很不容易，你的北方有一座小石桥高
高地跨过两边的山壁，可是桥的高度太高，即使是轻功绝顶的高手也跃
不上去。
LONG
	);
        set("item_desc", ([
            "lake":
                   "这是一个死水潭，潭水已经发绿，散发出阵阵的腥味。\n"
         ]) );

	set("exits", ([ /* sizeof() == 1 */
  "north" : "/d/oldpine/riverbank2",
  "south" : __DIR__"lake"
]));
	set("outdoors", "oldpine");
	set("resource/water", 1);
	setup();
}

void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{
	if( !arg || arg!="cliff" ) return 0;

	message_vision("$N一付不信邪的表情，开始小心翼翼地攀著石壁爬了上去。\n",
		this_player() );
	this_player()->move(__DIR__"cliff1");

	return 1;
}

