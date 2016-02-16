// feeblebolt.c

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	string msg;
	int damage, ap, dp;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("你要对谁施展这个法术？\n");

	if((int)me->query("mana") < 25 )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 10 )
		return notify_fail("你的精神没有办法有效集中！\n");

	me->add("mana", -25);
	me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) {
		write("你失败了。\n");
		return 1;
	}
	msg = HIW "$N口中喃喃地念著咒文，左手一挥，手中聚起一团白光射向$n！\n\n" NOR;

	ap = me->query_skill("spells");
	ap = ( ap * ap * ap / 4 ) * (int)me->query("sen") / 100;
	dp = target->query("combat_exp");
	if( random(ap + dp) > dp ) {
		damage = (int)me->query("max_mana") / 20 + random((int)me->query("eff_sen") / 10);
		damage -= (int)target->query("max_mana") / 30 + random((int)me->query("eff_sen") / 15);
		if( damage > 0 ) {
			msg +=  HIR "结果「嗤」地一声，白光从$p身上透体而过，拖出一条长长的黑气直射到\n"
					"两三丈外的地下！\n" NOR;
			target->receive_damage("sen", damage, me);
			target->receive_wound("sen", damage/3, me);
			me->improve_skill("necromancy", 1, 1);
		} else
			msg += "结果「嗤」地一声，白光从$p身上透体而过，无声无息地钻入地下！\n";
	} else
		msg += "但是被$n躲开了。\n";

	message_vision(msg, me, target);
	if( damage > 0 ) COMBAT_D->report_status(target);

	if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else 				target->kill_ob(me);
		}
		me->kill_ob(target);
	}

	me->start_busy(2);
	return 1;
}

