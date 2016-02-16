inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N使一招「伫倚危楼风细细」，手中$w如一风一般卷向$n的$l",
                "dodge":                -20,
                "damage":               30,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N使出蝶恋花剑中的「草色烟光残照里」，剑光向残照般洒向$n的$l",
                "dodge":                -20,
                "damage":               30,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N一招「无言谁会凭栏意」，手中$w默默的削向$n的$l",
                "dodge":                -30,
                "damage":               20,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w一式「拟把疏狂图一醉」对准$n的$l一连刺出七剑",
                "damage":                90,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N的$w凭空一指，一招「衣带渐宽终不悔」刺向$n的$l",
                "dodge":                20,
                "damage":               40,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手中$w向外一分，使一招「为伊消得人憔悴」反手对准$n$l一剑刺去",
                "dodge":                -20,
                "damage":               20,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练蝶恋花剑法。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return 
notify_fail("你的内力或气不够，没有办法练习蝶恋花剑法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("你按著所学练了一遍蝶恋花剑法。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("legend") + "/deisword/" + action;
}
 
int effective_level() { return 13;}

string *parry_msg = ({
        "$n使出一招「望极春愁」，手中的$v荡开了$N的$w。\n",
        "$n使出「黯黯生天际」，将$N的$w封于丈外。\n",
        "$n使出一招「强乐还无味」，手中的$v化做漫天残照，荡开了$N的$w。\n",
        "$n手中的$v一抖，一招「对酒当歌」，向$N拿$w的手腕削去。\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的$v舞得密不透风，一招「拟对强衣为」封住了$N的攻势。\n",
        "$n反手一招「伫望黯草无」，整个人消失在一团剑光之中。\n",
        "$n使出一招「倚极黯色言」，$v直刺$N的双手。\n",
        "$n将手中的$v一抖，一招招「把酒乐带伊」，迫得$N连连后退。\n",
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
        return 10;
}
int practice_bonus()
{
        return 5;
}
int black_white_ness()
{
        return 20;
}
