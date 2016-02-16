inherit SKILL;

string *dodge_msg = ({
        "$n一招「秋风起兮白云飞」轻轻巧巧地避了开去。\n",
        "只见$n身影一晃，一式「草木黄落兮雁南归」早已避在七尺之外。\n",
        "$n使出「兰有秀兮菊有芳」，轻轻松松地闪过。\n",
        "$n左足一点，一招「怀佳人兮不能忘」腾空而起，避了开去。\n",
        "可是$n使一招「泛楼船兮济汾河」，身子轻轻飘了开去。\n",
        "$n身影微动，已经藉一招「横中流兮扬素波」轻轻闪过。\n",
        "但是$n一招「箫鼓鸣兮发棹歌」使出，早已绕到$N身後！\n",
        "但是$n身形飘忽，轻轻一纵，一招「欢乐极兮哀情多」，避开这一击。\n",
        "$n身形往上一拔，一招「少壮几时兮奈老何」，一个转折落在数尺之外。\n",

});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练秋风步。\n");

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
                return notify_fail("你的气或内力不够，不能练秋风步法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}
int effective_level() { return 15;}

int learn_bonus()
{
        return -20;
}
int practice_bonus()
{
        return -10;
}
int black_white_ness()
{
        return 40;
}
