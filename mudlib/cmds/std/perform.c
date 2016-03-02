// perform.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object weapon;
        string martial, skill;
        int result;
        
        seteuid(getuid());

        if( me->is_busy() )
                return notify_fail("( 
你上一个动作还没有完成，不能施用外功。)\n");

        if( !arg ) return notify_fail("你要用外功做什麽？\n");

        if( sscanf(arg, "%s.%s", martial, arg)!=2 ) {
                if( weapon = me->query_temp("weapon") )
                        martial = weapon->query("skill_type");
                else
                        martial = "unarmed";
        }

        if( stringp(skill = me->query_skill_mapped(martial)) ) {
                notify_fail("你所使用的外功中没有这种功能。\n");
                if( SKILL_D(skill)->perform_action(me, arg) ) {
                        if( random(120) < (int)me->query_skill(skill) )
                                me->improve_skill(skill, 1, 1);
                        return 1;
                } else if( SKILL_D(martial)->perform_action(me, arg) ) {
                        if( random(120) < (int)me->query_skill(martial, 1) )
                                me->improve_skill(martial, 1, 1);
                        return 1;
                }
                return 0;
        }

        return notify_fail("你请先用 enable 指令选择你要使用的外功。\n");
}

int help (object me)
{
        write(@HELP
指令格式：perfrom [<武功种类>.]<招式名称> [<施用对象>]

如果你所学的外功(拳脚、剑法、刀法....)有一些特殊的攻击方式或招式，可以
用这个指令来使用，你必须先用 enable 指令指定你使用的武功，不指定武功种
类时，空手的外功是指你的拳脚功夫，使用武器时则是兵刃的武功。

若是你的外功中有种类不同，但是招式名称相同的，或者不属於拳脚跟武器技能
的武功(如轻功)，可以用 <武功>.<招式>  的方式指定，如：

perform sword.powerfocus 
perform move.reflexion

换句话说，只要是 enable 中的武功有特殊招式的，都可以用这个指令使用。
HELP
        );
        return 1;
}
 
