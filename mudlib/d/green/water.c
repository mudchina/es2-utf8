#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short","溪水边");
	set("long",@LONG
你来到了一条小溪的旁边，溪水很清澈，缓缓地向南流去，西面
灌木丛中隐隐的有条小路。
忽然水(water)中有一道亮光闪过，不过看不清是什么，你是否要下去
找一找(search)?
LONG
);
	set("exits",([
	"west" :__DIR__"outdoor",
	"north":__DIR__"stoneroom",
	]) );
	create_door("north","密门","south",DOOR_CLOSED);
	setup();
}

void init()
{
	add_action("do_search","search");
}

int do_search(string arg)
{
	object me,obj;
	
	me = this_player();
	if ( !arg || arg != "water" )
		return notify_fail("你要在那儿找?\n");

        message_vision("$N跳入溪水之中，开始仔细寻找....\n",me);		

	if ( me->query("八卦阵") ) {
	   if ( random(2) ) {
		obj = new("/d/green/obj/windsword");
		obj->move(me);
		message_vision("$N竟从水中找出一把"+HIW"追风剑"NOR+"!\n", me);
		return 1 ;
	   }
	   me->delete("八卦阵");
	}
        message_vision("$N在水中忙了半天，结果一无所获。\n",me);		
	return 1 ;
}

