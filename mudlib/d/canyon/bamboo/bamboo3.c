// Room: /d/canyon/bamboo/bamboo3.c

inherit ROOM;

void create()
{
	set("short", "竹林道");
	set("long", @LONG
北方有一个大黄石堵住去路，洋洋洒洒的蓝光从大黄石的四周漫
漫而出，竹林参天，在此成一半凹型，团团围住了北方的去路，若想
一窥究竟，看来非得推开这巨大的黄石才行，风势愈来愈强，四周的
竹子发出了嗡嗡的鸣声，彷佛叫人不要靠近，此地之主人看似不欢迎
别人来参观。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"bamboo2",
]));

	setup();
}

void init ()
{
	add_action("do_move","move");
	add_action("do_enter","enter");
	add_action("go_enter","go");
}
int do_move(string arg)
{
	object me;
	
	if ( arg!="stone" ) return 0;
	
	me=this_player();
	
	if ( ((int)me->query("force") < 560) ||
	     ((int)me->query("max_force") < 560) ||
	     ((int)me->query("force_factor") < 40 ) ) { 
		tell_object(me, "你出力不太够喔！\n");
		return 1;
	}

	me->receive_damage("gin",20);
	me->receive_damage("kee",60);
	me->receive_damage("sen",20);
	
	if( query("exits/enter") ) return 1;
	
	set("exits/enter",__DIR__"train");
        message_vision("$N将大黄石缓缓的向左边移动，而出现了一个小小的隙缝。\n"
        		,me);
	return 1;
}

int do_enter()
{
	if( !query("exits/enter") ) return 0;
	
	message_vision("当$N通过隙缝，大黄石又急速地合闭。\n",this_player());
	delete("exits/enter");
	this_player()->move(__DIR__"train");
	return 1;
}

int go_enter(string arg)
{
	if( !query("exits/enter") ) return 0;
	        
	if( arg!="enter" ) return 0;
	
	message_vision("当$N通过隙缝，大黄石又急速地合闭。\n",this_player());
	delete("exits/enter");
	this_player()->move(__DIR__"train");
	return 1;
}
