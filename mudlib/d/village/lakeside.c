// Room: /d/village/lakeside.c

inherit ROOM;

void create()
{
	set("short", "玉螺湖畔");
	set("long", @LONG
玉螺湖以产的螺蛳洁白如玉而得名，并且湖中盛产味道鲜美的鲈鱼。
有很多渔夫泛舟湖上，以网鱼捕螺为生。但现在他们都站在岸边，面带愁
容，不清楚有什么变故发生。岸边还散落了几艘木船(boat)。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lake",
  "east" : __DIR__"road7",
]));
	set("objects",([
		__DIR__"npc/fisher":3,
	]) );
	
	set("item_desc", ([
		"boat":
		"关内能经常见到的渔船，你可以划着(paddle)它到湖中心。
" ]) );
	set("no_clean_up", 0);

	setup();
	//replace_program(ROOM);
}

void init()
{
	add_action("do_paddle", "paddle");
}

int do_paddle(string arg)
{
	if(!arg || arg=="")
		return notify_fail("你要划什么？\n");
	if( arg!="boat" && arg!="船" )
		return notify_fail("不划船你想划什么？\n");
	message_vision("$N跳上渔船，奋力向湖心划去。\n", this_player());
	write("你终于划到湖中心了。\n");
	this_player()->move(__DIR__"lake");
	return 1;
}

int valid_leave(object me,string dir)
{
        if( dir=="west" )
            return notify_fail( "这么大的一片湖，你想走过去吗？\n" );
        return ::valid_leave(me,dir);
}
