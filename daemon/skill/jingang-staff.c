// cloudstaff.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N使一招「天光乍现」，手中$w扫向$n下盘！",
                "damage":               40,
                "dodge":                10,
                "parry":                -40,
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N挥起$w，一招「雨後初晴」攻向$n$l！",
                "damage":               40,
                "dodge":                20,
                "parry":                -60,
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N横过手中$w，使出「浮云写意」击向$n$l！",
                "damage":               40,
                "dodge":                10,
                "parry":                -40,
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N使出一招「游龙穿云」，$w一挺撞向$n$l！",
                "damage":               40,
                "dodge":                10,
                "parry":                -40,
                "damage_type":  "挫伤"
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 50 )
                return 
notify_fail("你的膂力还不够，也许该练一练内力来增强力量。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="staff") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "staff" )
                return 
notify_fail("你必须先找一根木杖或者是类似的武器，才能练杖法。\n");

        if( (int)me->query("kee") < 60 )
                return 
notify_fail("你的体力不够练这门杖法，还是先休息休息吧。\n");
        me->receive_damage("kee", 60);
        return 1;
}
 
