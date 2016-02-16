// void_sense.c

#include <ansi.h>

inherit SSERVER;

int conjure(object me, object target)
{
	if( target ) return notify_fail("空识神通只能对自己使用。\n");
	if( me->query("atman") < 50 )
		return notify_fail("你的灵力不够！\n");
	me->add("atman", -50);
	me->receive_damage("gin", 50);
	message_vision(HIY "$N盘膝而座，开始运用空识神通静思入定 ...\n" NOR, me);
	if( random(me->query_skill("magic")) > (int)me->query_int() ) {
		if( random(me->query("max_atman")) < (int)me->query("atman")/2 ) {
			me->add("learned_points", 1);
			write( HIR "你觉得脑中一片混乱，你的潜能降低了！\n" NOR );
			return 1;
		}
		if( (int)me->query("potential") - (int)me->query("learned_points") < 500 ) {
			me->add("potential", random( (int)me->query_spi() / 5 ) + 1);
			write( HIG "你的潜能提高了！\n" NOR );
			return 1;
		}
	}
	write("可是你只觉得一无所获。\n");
	return 1;
}
