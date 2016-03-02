// bandaged.c

#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( (int)me->query("eff_kee") < (int)me->query("max_kee") )
		me->receive_curing("kee", 3);
	
	me->apply_condition("bandaged", duration - 1);
	if( !duration ) return 0;

	return CND_CONTINUE;
}
