// gouyee.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
        if( (int)me->query("max_mana") < (int)me->query_skill("gouyee") * 5 )
                return 
notify_fail("你的魔力不够，无法提升谷衣心法的造诣。\n");

        return 1;
}

int practice_skill(object me)
{
        return 
notify_fail("谷衣心法只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
        return CLASS_D("taoist") + "/gouyee/" + func;
}
 
