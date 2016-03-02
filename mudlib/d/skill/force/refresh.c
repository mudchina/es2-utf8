// refresh.c

int exert(object me, object target)
{
	if( target ) return notify_fail("你只能用内功\收□自己的心神。\n");

	if( (int)me->query("force") < 20 )
		return notify_fail("你的内力不够。\n");

	me->receive_heal("sen", 10 + (int)me->query_skill("force")/3 );
	me->add("force", -20);

	message_vision("$N略一凝神，吸了口气，精神看起来清醒多了。\n", me);

	if( me->is_fighting() ) me->start_busy(1);

	return 1;
}
