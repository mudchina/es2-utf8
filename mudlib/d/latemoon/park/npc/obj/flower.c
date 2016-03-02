inherit COMBINED_ITEM;

void create()
{
    set_name("小花蕊", ({ "pistil" }));
    set("long", "这是一朵金黄色的奇特花蕊，有一种淡淡香气。\n");
    set("unit", "朵");
    set("base_unit", "株");
    set("base_weight", 20);
	set_amount(1);
}

void init()
{
	if( this_player()==environment() )
		add_action("do_eat", "eat");
}

int do_eat(string arg)
{
    int I,J;
    object me;

    me = this_player();
    J = me->query_condition("rose_poison");
    if ( J < 10)  I = 0;
    if ( J >= 10) I = J - 10;
    if( !arg || arg != "pistil" ) return notify_fail("你要吃甚么呢? \n");

	message_vision(
       "$N拿出一朵小花蕊，一口给吞了下去。\n"
       "只见$N脸上泛起一阵红晕，整个人看起来好多了! \n",me );
    me->receive_heal("sen", 50);
    me->apply_condition("rose_poison", I);

	add_amount(-1);
	return 1;
}
