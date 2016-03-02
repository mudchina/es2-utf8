// recover.c

inherit SSERVER;

int exert(object me, object target)
{
	int heal, cost, heal1;

	if( target != me ) return notify_fail("你只能用内功\调匀自己的气息。\n");

	if( (int)me->query("force") < 20 ) return notify_fail("你的内力不够。\n");

	heal1 = (int)me->query("eff_kee") - (int)me->query("kee");

	if( heal1 < 1 ) return notify_fail("你的气已经恢复到上限了。\n");

//	if( (int)me->query_skill("force") < 1 ) return notify_fail("你失败了。\n");
//	cost = heal * 10 / ((int)me->query_skill("force")/5+1);

	cost = 20;
	if (heal1 > (int)me->query_skill("force")/3+10)
		heal = (int)me->query_skill("force")/3+10;
	else 
		heal = heal1;
 
//	if( (int)me->query("force") < cost ) {
//		heal = heal * (int)me->query("force") / cost;
//		me->set("force", 0);
//		me->receive_heal("kee", heal);
//	} else {
		me->add("force", - cost);
		me->receive_heal("kee", heal);
//	}

	message_vision("$N深深吸了几口气，脸色看起来好多了。\n", me);

	if( me->is_fighting() ) me->start_busy(1);

	return 1;
}
