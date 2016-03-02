inherit SKILL;

mapping *action = ({
        ([      "action":               "$N使一招「对酒当歌」，手中$w风似地向$n的$l斩去！",
                "damage":               70,
                "dodge":                70,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N弯刀似月，$w随著一招「人生几何」由下而上撩往$n的$l",
                "damage":               40,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N身形一转，一招「譬如朝露」$w如朝露闪烁，斩向$n的$l",
                "damage":               20,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N舞动$w，一招「去日苦多」往$n的$l斜斜砍出一刀",
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N手中$w一晃，一招「慨当以慷」迅捷无伦地劈向$n的$l",
                "damage":               70,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N提气丹田，身型咋展，一招「忧思难忘」直劈$n$l",
                "damage":               30,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N移步侧身，使一招「何以解忧」刀光霍霍斩向$n的$l",
                "damage":               50,
                "damage_type":  "割伤"
        ]),
});

int valid_learn(object me)
{
        return 1;
}

int valid_enable(string usage)
{
        return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "blade" )
                return notify_fail("你必须先找一把刀，才能练刀法。\n");

        if( (int)me->query("kee") < 40 )
                return notify_fail("你的体力不够练这门刀法，还是先休息休息吧。\n");
        me->receive_damage("kee", 40);
        return 1;
}
/*int effective_level() { return 25;}
*/
string *parry_msg = ({
        "$n使出一招「唯有杜康」，用手中的$v急削$N的五指。\n",
        "$n左脚踏前一步，一招「青青子衿」，手中的$v从侧面飘向$N之必救。\n",
        "$n手中的$v一抖，挽出一片刀花，一招「悠悠我心」，撒向$N的全身。\n",
        "$n微退一步，手中的$v划出一条光弧，一招「但为君故」，将$N的全身围住。\n",
});

string *unarmed_parry_msg = ({
"$n使出一招「沉吟至今」，用手中的$v急砍$N。\n",
"$n左脚踏前踏，一招「呦呦鹿鸣」，手中的$v挥向$N之必救。\n",
"$n手中的$v一抖，一招「山不厌高」，奔向$N。\n",
"$n手中的$v划出一招「天下归心」，将$N的全身围住。\n",
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
        return 40;
}
int practice_bonus()
{
        return 20;
}
int black_white_ness()
{
        return 30;
}
