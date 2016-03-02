// heart_sense.c

#include <ansi.h>

inherit SSERVER;

int conjure(object me, object target)
{
	if( !target || !target->is_character() )
		return notify_fail("你要对谁使用心识神通？\n");
	if( target->is_corpse() )
		return notify_fail("来不及了，只有活人才能救醒。\n");

	if( (int)me->query("atman") < 50 ) return notify_fail("你的灵力不够！\n");
	me->add("atman", -50);
	me->receive_damage("sen", 30);
	message_vision( HIY "$N一手放在$n的天灵盖\上，一手贴在$n的後心，闭上眼睛缓缓低吟 ...\n" NOR,
		me, target );
	if( random(me->query("max_atman")) > 100 )
		target->revive();
	else
		me->unconcious();
	if( me->is_fighting() )
		me->start_busy(3);
	return 1;
}
