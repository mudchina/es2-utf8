// meditate.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int sen_cost, mana_gain;

	seteuid(getuid());
	
	if( me->is_fighting() ) return notify_fail("战斗中冥思——找死吗？\n");

	if( !arg
	||	!sscanf(arg, "%d", sen_cost) )
		return notify_fail("你要花多少精神冥思？\n");

	if( sen_cost < 10 ) return notify_fail("你最少要花 10 点「神」才能冥思。\n");

	if( (int)me->query("sen") < sen_cost )
		return notify_fail("你现在精神太差了，进行冥思将会迷失，永远醒不过来！\n");

	if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 70 )
		return notify_fail("你现在身体状况太差了，无法集中精神！\n");

	if( (int)me->query("gin") * 100 / (int)me->query("max_gin") < 70 )
		return notify_fail("你现在身体状况太虚弱了，无法进入冥思的状态！\n");

	write("你盘膝而坐，静坐冥思了一会儿。\n");

	me->receive_damage("sen", sen_cost);

	// This function ranged from 1 to 15 when sen_cost = 30
	mana_gain = sen_cost * ((int)me->query_skill("spells") 
		+ (int)me->query("spi") ) / 300;

	if( mana_gain < 1 ) {
		write("但是当你睁开眼睛，只觉得脑中一片空白。\n");
		return 1;
	}

	me->add("mana", mana_gain );

	if( (int)me->query("mana") > (int)me->query("max_mana") * 2) {
		if( (int)me->query("max_mana") >= (int)me->query_skill("spells", 1) * 10) {
			write("当你的法力增加的瞬间你忽然觉得脑中一片混乱，似乎魔力的提升已经到了瓶颈。\n");
		} else {
			write("你的魔力提高了！\n");
			me->add("max_mana", 1);
		}
		me->set("mana", me->query("max_mana"));
	}	
	
	return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : meditate [<耗费「神」的量，预设值 30>]
 
静坐冥思，将游离的精神力有效地集中凝聚成能够用来施展法术的能量
，藉以增加自己的法力。

请参考 help stat 
HELP
        );
        return 1;
}
