// regenerate.c

int exert(object me, object target)
{
	if( target ) return notify_fail("你只能用内功\提振自己的精力。\n");

	if( (int)me->query("force") < 20 )
		return notify_fail("你的内力不够。\n");

	me->receive_heal("gin", 10 + (int)me->query_skill("force")/3 );
	me->add("force", -20);

	message_vision("$N深深吸了口气，手脚活动了几下，整个人看起来有活力多了。\n", me);

	if( me->is_fighting() ) me->start_busy(1);

	return 1;
}
