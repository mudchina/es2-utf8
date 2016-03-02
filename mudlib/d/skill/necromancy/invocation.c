// invocation.c

int cast_spell(object me, object target)
{
	object soldier;

	if( !me->is_fighting() )
		return notify_fail("只有战斗中才能召唤天将！\n");
	
	if( (int)me->query("mana") < 100 )
		return notify_fail("你的法力不够了！\n");

	if( (int)me->query("sen") < 60 )
		return notify_fail("你的精神无法集中！\n");

	message_vision("$N喃喃地念了几句咒语。\n", me);

	me->add("mana", -100);
	me->receive_damage("sen", 60);

	if( random(me->query("max_mana")) < 200 ) {
		message("vision", "但是什么也没有发生。\n", environment(me));
		return 1;
	}

	seteuid(getuid());
	soldier = new("/obj/npc/heaven_soldier");
	soldier->move(environment(me));
	soldier->invocation(me);

	return 1;
}
