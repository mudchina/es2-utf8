// Room: /d/village/lake.c

inherit ROOM;

void create()
{
	set("short", "玉螺湖");
	set("long", @LONG
这里是玉螺湖的湖心，湖面上丝丝雾气蒸起，周围静得出奇，心跳声
都听的见。你仔细地向湖底看去，忽的见白光一闪，如果想看个究竟，可
以潜入湖中(dive)，但理智告诉你一定要安全第一！西面远处是朦胧的群
山，东边岸上的渔夫似乎冲着你比比划划。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lakeside",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

void init()
{
	add_action("do_paddle","paddle");
	add_action("do_dive","dive");
}

int valid_leave(object me,string dir)
{
	if( dir=="east" )
		return notify_fail("你正站在船头，向东走一小步就会掉入湖中！你不想这样吧？\n");
	return valid_leave( me,dir);
}

int do_paddle(string arg)
{
        if(!arg || arg=="")
                return notify_fail("你要划什么？\n");
        if( arg!="boat" && arg!="船" )
                return notify_fail("不划船你想划什么？\n");
        message_vision("$N你划动双桨，小船慢慢向岸边漂去。\n
", this_player());
        write("你终于划到湖岸边。\n");
        this_player()->move(__DIR__"lakeside");
        return 1;
}

int do_dive(string arg)
{
	message_vision("$N深深吸了一口气，一个猛子潜入水中！\n", this_player() );
	write("你越潜越深，突然眼前一亮，一处湖底发出光亮。你用拳一砸，那\n
               湖底竟然碎了，原来是一层冰！你随着水流被冲进一个岩洞中。\n");
	this_player()->move(__DIR__"lakebottom1");
	return 1;
}
