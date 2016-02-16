inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N使出一招「苦海端无涯」，左掌虚幌，右掌穿出击向$n的$l",
                "dodge":                -30,
                "parry":                10,
                "force":                50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出一招「地狱似有门」，左掌化虚为实击向$n的$l",
                "dodge":                -10,
                "parry":                -30,
                "force":                 70,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出密宗大手印中的「天堂却无路」，一掌拍向$n的$l",
                "dodge":                -30,
                "parry":                10,
                "force":                50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双掌一错，使出「密宗为独尊」，对准$n的$l连续拍出",
                "dodge":                10,
                "parry":                -30,
                "force":                160,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N左掌立于胸前，右掌推出，一招「万念皆是空」击向$n$l",
                "dodge":                -20,
                "parry":                -30,
                "force":                140,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出「佛云以杀止杀」，身形凌空飞起，从空中当头向$n的$l出掌攻击",
                "dodge":                -70,
                "parry":                -10,
                "force":                280,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练密宗大手印必须空手。\n");
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
int effective_level() { return 8;}
 
string *parry_msg = ({
        "$n双掌微合，使出一招「千里迎刹佛」，「啪」的一声将$N的$w夹在双掌之间。\n",
        "$n略一转身，一招「撒手离红尘」拍向$N拿着$w的手。\n",
        "$n使出「粘」字诀，双掌一划，引偏了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n步走阴阳，一招「我佛慈悲怀」虚空拍出三掌，逼得$N撤招自保。\n",
        "$n施展出「万象皆归空」，轻描淡写的化解了$N的攻势。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
        return 50;
}
int practice_bonus()
{
        return 25;
}
int black_white_ness()
{
        return 100;
}

