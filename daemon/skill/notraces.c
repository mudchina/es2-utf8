inherit SKILL;

string *dodge_msg = ({
        "$n一招「夕阳残雪」轻轻巧巧地避了开去。\n",
        "只见$n身影一晃，一式「腾云驾雾」早已避在七尺之外。\n",
        "$n使出「鱼翔蓝天」，轻轻松松地闪过。\n",
        "$n左足一点，一招「步履云端」腾空而起，避了开去。\n",
        "可是$n使一招「踏雪无痕」，身子轻轻飘了开去。\n",
        "$n身影微动，已经藉一招「龙腾万里」轻轻闪过。\n"
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练踏雪无痕。\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("你的气或内力不够，不能练踏雪无痕。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}
int effective_level() { return 12;}

int learn_bonus()
{
        return 20;
}
int practice_bonus()
{
        return 10;
}
int black_white_ness()
{
        return 20;
}

