// exercise.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int kee_cost, force_gain;

        seteuid(getuid());
        
        if( me->is_fighting() )
                return notify_fail("战斗中不能练内功，会走火入魔。\n");

        if( !stringp(me->query_skill_mapped("force")) )
                return notify_fail("你必须先用 enable 
选择你要用的内功心法。\n");

        if( !arg
        ||      !sscanf(arg, "%d", kee_cost) )
                return notify_fail("你要花多少气练功？\n");

        if( kee_cost < 10 ) return notify_fail("你最少要花 10 
点「气」才能练功。\n");

        if( (int)me->query("kee") < kee_cost )
                return 
notify_fail("你现在的气太少了，无法产生内息运行全身经脉。\n");

        if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 70 )
                return notify_fail("你现在精神状况太差了，无法凝神专一！\n");

        if( (int)me->query("gin") * 100 / (int)me->query("max_gin") < 70 )
                return notify_fail("你现在精力不够，无法控制内息的流动！\n");

        write("你坐下来运气用功，一股内息开始在体内流动。\n");

        me->receive_damage("kee", kee_cost);

        // This function ranged from 1 to 15 when kee_cost = 30
        force_gain = kee_cost * ((int)me->query_skill("force", 1)
                + (int)me->query("con") ) / 300;

        if( force_gain < 1 ) {
                write("但是当你行功完毕，只觉得全身□麻。\n");
                return 1;
        }

        me->add("force", force_gain );

        if( (int)me->query("force") > (int)me->query("max_force") * 2) {
                if( (int)me->query("max_force") >= 
                        ((int)me->query_skill("force", 1) + 
me->query_skill("force")/5) * 10 ) {
                        
write("当你的内息遍布全身经脉时却没有功力提升的迹象，似乎内力修为已经遇到了瓶�
薄n");
                } else {
                        write("你的内力增强了！\n");
                        me->add("max_force", 1);
                }
                me->set("force", me->query("max_force"));
        }       
        
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : exercise [<耗费「气」的量，预设值 30>]

运气练功，控制体内的气在各经脉间流动，藉以训练人体肌肉骨骼的耐
力、爆发力，并且用内力的形式将能量储备下来。

请参考 help stats
HELP
        );
        return 1;
}
 
