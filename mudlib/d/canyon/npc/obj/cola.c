inherit ITEM;

#include <ansi.h>

void create()
{
	set_name(HIB"一瓶深蓝色的可乐"NOR,({ "cola" }) );
	set("long", "这是一瓶只有在Void 才见的到的奖品，口渴使你忍不住想
喝他一口(drink)。\n");
	set("unit", "瓶");
	set("base_weight", 200);
}

void init()
{
	if( this_player()==environment() )
		add_action("do_drink", "drink");
}

int do_drink(string arg)
{
	object ob;

	if( !arg || arg != "cola") 
		return notify_fail("你要喝甚么呢? \n");

	message_vision( MAG
 	"$N喝了口可乐,舔了舔嘴边,似乎回味无穷.....\n"+HIR
 	"$N脸上露出诡异的表情....\n" NOR,this_player()  
 	); //end_message_vision
	message_vision(WHT"这瓶可乐被$N喝完了，$N随手一丢，说也奇怪地就不见了。
				\n"NOR,this_player() );

    	
    	this_player()->set("water",this_player()->max_water_capacity());
	destruct(this_object());
	
	return 1;
}
