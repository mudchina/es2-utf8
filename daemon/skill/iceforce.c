// iceforce.c2

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("意寒功只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
        return CLASS_D("dancer") + "/iceforce/" + func;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        mixed foo;

        foo = ::hit_ob(me, victim, damage_bonus, factor);
        if( intp(foo) && (damage_bonus + foo > 0) ) {
                if( random(me->query_skill("iceforce")) > (damage_bonus + 
foo) ) {
                        victim->receive_wound("kee", (damage_bonus + foo));
                        victim->apply_condition("iceshock", factor/3);
                        return 
"$N的招式挟著一股阴寒无比的劲风使得$n不禁打了个寒噤。\n";
                }
        }
        return foo;
}
 
