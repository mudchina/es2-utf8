// celestrike.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N使出一招「大天罗式」，右掌穿出击向$n的$l",
                "dodge":                -30,
                "parry":                10,
                "force":                200,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出一招「大天罗式」，左掌化虚为实击向$n的$l",
                "dodge":                -10,
                "parry":                -30,
                "force":                170,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出天邪掌法「小天罗式」，如鬼魅般欺至$n身前，一掌拍向$n的$l",
                "dodge":                -30,
                "parry":                10,
                "force":                150,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双掌一错，使出「雪阳三连月」，对准$n的$l连续拍出三掌",
                "dodge":                10,
                "parry":                -30,
                "force":                260,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N左掌画了个圈圈，右掌推出，一招「灵动五方鼓」击向$n$l",
                "dodge":                -20,
                "parry":                -30,
                "force":                240,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出「风雷七星断」，身形散作七处同时向$n的$l出掌攻击",
                "dodge":                -70,
                "parry":                -10,
                "force":                280,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N吐气扬声，一招「气撼九重天」双掌并力推出",
                "parry":                -40,
                "force":                320,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练天邪神掌必须空手。\n");
        if( (int)me->query_skill("celestial", 1) < 20 )
                return 
notify_fail("你的天邪神功火候不足，无法练天邪掌法。\n");
        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力太弱，无法练天邪掌法。\n");
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
                return notify_fail("你的体力不够了，休息一下再练吧。\n");
        if( (int)me->query("force") < 5 )
                return notify_fail("你的内力不够了，休息一下再练吧。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}
 
