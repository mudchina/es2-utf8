#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
     set_name(HIW "白凤丸" NOR ,({"white pill","pill" }));
	set("long",
   "这是一颗纯白亮丽的丸子，闻了闻有一种上等药材的味道。\n");
	set("unit", "颗");
	set("base_unit", "颗");
	set("base_weight", 200);
	set_amount(1);
}

void init()
{
	if( this_player()==environment() )
		add_action("do_eat", "eat");
}

int do_eat(string arg)
{
    if( !arg || arg != "pill")  return notify_fail("你要吃甚么呢? \n");

	message_vision(
	   "$N拿出一颗大丸子，一口给吞了下去。\n"

	"只见$N全身冒出一阵白烟，整个人看起来非常有精神! \n",this_player());
    this_player()->receive_heal("gin", 100);
	this_player()->receive_heal("kee", 300);
	this_player()->receive_heal("sen",100);

	add_amount(-1);
	return 1;
}
