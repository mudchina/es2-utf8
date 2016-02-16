// recover.c

int exert(object me, object target)
{
	if( target ) return notify_fail("你只能用内功\调匀自己的气息。\n");

	if( (int)me->query("force") < 20 )
		return notify_fail("你的内力不够。\n");

	me->receive_heal("kee", 10 + (int)me->query_skill("force")/3 );
	me->add("force", -20);

	message_vision("$N深深吸了几口气，脸色看起来好多了。\n", me);

	if( me->is_fighting() ) me->start_busy(1);

	return 1;
}
