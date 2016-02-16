#include <room.h>

inherit ROOM;

void create()
{
	set("short","内厅");
	set("long", @LONG
走入内厅，你看到袭地铺满红毯。四面相对十二张雕漆椅上，都
是一色灰鼠椅□小褥，厅中摆了小屏风，四周挂满山水墨画。一个木
隔架，旁边还有一碧纱橱(closet)。
LONG
	);
	set("item_desc", ([
		"closet" : @TEXT
这是一个上等木材作成的小橱子，里面放了一些物品。
你看到一件件的美丽衣饰，真想取出(take cloth)看看。
TEXT
	]) );

	set("exits", ([ /* sizeof() == 2 */
		"west" :__DIR__"latemoon4",
	]));

    set("objects",([
        __DIR__"npc/zauron" :  1 ]) );
	create_door("west","仪门","east", DOOR_CLOSED);
	setup();
}

void init()
{
	add_action("do_take", "take");
	add_action("do_search","search");
}

void reset()
{
	::reset();
	set("take_available" , 2);
	set("make_cockroach", 5);
}

int do_take(string arg)
{
	object obj;

	if( !arg ) return notify_fail("你要拿什么 ? \n");
	if( arg !="cloth" ) { 
		if ( query("make_cockroach") ) {
			message_vision("$N一声尖叫 ! 突然出现一只大蟑螂。\n",this_player());
			obj = new(__DIR__"npc/cockroach");
			obj->move(environment(this_player()));
			add("make_cockroach", -1);
		}
		return 1;
	}
	if( query("take_available") ) {
		obj = new(__DIR__"obj/skirt");
		obj->move(this_player());
		message_vision("$N从橱子内取出$n。\n",this_player(),obj);
		add("take_available", -1);
		return 1;
	}
	write("橱子内的衣服好像被拿光了。\n");
	return 1;
}

int do_search(string arg)
{
	object obj,who;

	who = this_player();
	if ( !arg )	return notify_fail("你要找什么?\n");
	if ( arg !="bracelet" )	{
		 write("你盲目的找著，但无发现什么!\n");
	  return 1;
	}
	else  {
	if( !who->query_temp("moon/问题二") ) {
	 write("你盲目的找著，但无发现什么!\n");
		return 1;
	}
	 if ( who->query_temp("latemoon/手镯") ) {
		 write("你翻箱倒柜想找出手镯，但似乎毫无所获。\n");
		 return 1;
	 }
     obj = new("/d/latemoon/obj/bracelet");
	 obj->move(who);
	 message_vision("$N从橱子内取出$n。\n",this_player(),obj);
	 who->set_temp("latemoon/手镯", 1);
	return 1;
	}
}
