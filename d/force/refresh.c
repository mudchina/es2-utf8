// refresh.c

inherit SSERVER;

int exert(object me, object target)
{
	int heal, heal1, heal2, cost=20;

	if( target != me ) return notify_fail("你只能用内功\收□自己的心神。\n");

	if( (int)me->query("force") < 20 ) return notify_fail("你的内力不够。\n");

	heal1 = (int)me->query("eff_sen") - (int)me->query("sen");

	if( heal1 < 1 ) return notify_fail("你的神已经恢复到上限了。\n");

	heal2 = (int)me->query_skill("force")/3 + 10;
	heal = (heal1 - heal2) ? heal2 : heal1;

//	if( (int)me->query_skill("force") < 1 ) return notify_fail("你失败了。\n");
//	cost = heal * 10 / ((int)me->query_skill("force")/5+1);

//	if( (int)me->query("force") < cost ) {
//		heal = heal * (int)me->query("force") / cost;
//		me->set("force", 0);
//		me->receive_heal("sen", heal);
//	} else {
		me->add("force", - cost);
		me->receive_heal("sen", heal);
//	}

	message_vision("$N微一凝神，缓缓地吸了口气，看起来有精神多了。\n", me);

	if( me->is_fighting() ) me->start_busy(1);

	return 1;
}
