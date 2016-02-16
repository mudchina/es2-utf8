// poison.c

#include <condition.h>

int update_condition(object me, mapping info)
{
	if( !mapp(info) ) return 0;

	me->receive_damage("kee", info["damage"]);
	me->receive_wound("kee", info["damage"] / 2);

	info["duration"] --;

	me->apply_condition("snake_poison", info);
	tell_object(me, info["message"] );
	if( info["duration"] < 1 ) return 0;

	return CND_CONTINUE;
}
