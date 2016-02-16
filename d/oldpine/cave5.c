// Room: /d/oldpine/cave5.c

inherit ROOM;

string look_wall ();

void create()
{
	set("short", "山洞");
	set("long", @LONG
你现在已经到达山洞的深处了, 耶...东面就是洞口了, 还可以听
见外面瀑布的水声, 仔细的观察石壁(wall), 可以发现上面有一些用利
剑雕刻的字....
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
		"eastdown" : __DIR__"waterfall",
		]));

	set("item_desc", ([
		"wall" : (: look_wall :),
		]) );

	set("objects", ([
		__DIR__"npc/skeleton":	1,
		]) );

	setup();
}

void init ()
{
	add_action ("do_bury", "bury");
}

int do_bury (string arg)
{
	object obbook, obsk;
	int ikar;
 
        if( !arg ) return notify_fail("你要埋什么？\n");
        if( arg != "skeleton" || !objectp(obsk = present(arg, environment(this_player()))) )
                return notify_fail("这里没有这样东西。\n");

	message_vision ("$N小心翼翼地埋好了那具骸骨。\n",this_player());

	obsk->move("/obj/void");

	ikar = (int ) random((int) (this_player()->query("kar"))+10); 
	if (ikar > 25) { 
		message_vision("$N听见山洞顶部的石壁「喀喇」地一声响，一本书坠落下来。\n", this_player());
		obbook = new(__DIR__"npc/obj/parrybook");
		obbook->move(__DIR__"cave5");
		return 1;
		}
	    else if (ikar > 20) 
		message_vision("$N只看见山洞顶部纷纷扬扬飘下几张纸片来。\n",this_player());
			
	message_vision ("$N听得「轰」的一声响，已经从这摔了下去\n", this_player());
	this_player()->move(__DIR__"waterfall");
	
	return 1;
}

string look_wall ()
{
	return ("老夫南危水, 乃是昔年水烟阁五长老中第一高手,
一生醉心武学, 集天邪、封山两派之所长, 为营救盟主遭小人暗算,
埋骨于此。男子汉大丈夫死不足惜, 只可恨一身武学尚无传人!
葬(bury)我遗骨者老夫将赠以过招要旨, 唉......
");
} 
