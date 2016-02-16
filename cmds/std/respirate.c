// respirate.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int gin_cost, atman_gain;
	string magic_skill;

	seteuid(getuid());
	
	if( me->is_fighting() )
		return notify_fail("战斗也是一种修行，但不能和灵力的修行同时进行。\n");

	if( !arg
	||	!sscanf(arg, "%d", gin_cost) )
		return notify_fail("你要花多少精力修行？\n");

	if( gin_cost < 10 ) return notify_fail("你最少要花 10 点精力才能进行修行。\n");

	if( (int)me->query("gin") < gin_cost )
		return notify_fail("你现在精力不足，无法修行灵力！\n");

	if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 70 )
		return notify_fail("你现在身体状况太差了，无法集中精神！\n");

	if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 70 )
		return notify_fail("你现在精神状况太差了，无法控制自己的心灵！\n");

	write("你闭上眼睛开始打坐。\n");

	me->receive_damage("gin", gin_cost);

	// This function ranged from 1 to 15 when gin_cost = 30
	atman_gain = gin_cost * ((int)me->query_skill("magic") 
		+ (int)me->query("spi") ) / 300;

	if( atman_gain < 1 ) {
		write("但是你一不小心却睡著了。\n");
		return 1;
	}

	me->add("atman", atman_gain );

	if( (int)me->query("atman") > (int)me->query("max_atman") * 2) {
		if( (int)me->query("max_atman") >= (int)me->query_skill("magic", 1) * 10 ) {
			write("你忽然觉得一阵天旋地转，头涨得像要裂开一样，似乎灵力的修行已经遇到了瓶颈。\n");
		} else {
			write("你的道行提高了！\n");
			me->add("max_atman", 1);
		}
		me->set("atman", me->query("max_atman"));
	}	
	
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : respirate [<耗费「精」的量，预设值 30>]
 
打坐修行，利用「炼精化气，炼气化神，炼神还虚」的方法将你的精力
转变成灵力。

请参考 help stats
HELP
        );
        return 1;
}
