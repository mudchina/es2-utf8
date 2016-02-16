// astral_vision.c

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int skill;

	if( me->query_temp("apply/astral_vision") )
		return notify_fail("你已经施展过阴阳眼的法术了。\n");

	if( (int)me->query("mana") < 30 )
		return notify_fail("你的法力不够。\n");

	skill = me->query_skill("spells");

	me->add("mana", - 30);
	me->receive_damage("sen", 5);

	message_vision(
		HIB "$N微一凝神，闭著眼睛念了几句咒语，施展「阴阳眼」法术。\n" NOR, me);

	me->add_temp("apply/astral_vision", 1);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill);

	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me)
{
	me->add_temp("apply/astral_vision", -1);
	tell_object(me, "你的阴阳眼法术失效了。\n");
}
