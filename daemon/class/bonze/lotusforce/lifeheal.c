// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( !target )
		return notify_fail("你要用真气为谁疗伤？\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功\疗伤！\n");

	if( (int)me->query("force") - (int)me->query("max_force") < 150 )
		return notify_fail("你的真气不够。\n");

	if( (int)target->query("eff_kee") < (int)target->query("max_kee") / 5 )
		return notify_fail( target->name() + "已经受伤过重，经受不起你的真气震□！\n");

	message_vision(
		HIY "$N坐了下来运起内功\，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n\n"
		"过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n" NOR,
		me, target );

	target->receive_curing("kee", 10 + (int)me->query_skill("force")/3 );
	me->add("force", -150);
	me->set("force_factor", 0);

	return 1;
}
