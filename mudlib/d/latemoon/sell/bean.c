inherit COMBINED_ITEM;

void create()
{
	set_name("仙豆", ({"sen-bean"}));
	set("long",	"这是一粒有点奇怪的豆子，闻了闻有一种上等药材的味道。\n");
	set("unit", "粒");
	set("base_unit", "粒");
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
	if( !arg || arg != "sen-bean")  return notify_fail("你要吃甚么呢? \n");

	message_vision(
	   "$N拿出一粒小丸子，一口给吞了下去。\n"
	   "只见$N脸上泛起一阵红晕，整个人看起来好多了! \n",this_player()  );
	this_player()->receive_heal("gin", 50);
	this_player()->receive_heal("kee", 100);
	this_player()->receive_heal("sen", 50);

	add_amount(-1);
	return 1;
}
