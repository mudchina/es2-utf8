// mysterrier.c

inherit SKILL;

string *dodge_msg = ({
        "$n身影一转，轻易地避开了这一招。\n",
        "$n身法飘忽，左一点，右一顿，早已闪在一旁。\n",
        "但是$n身影一侧，在间不容发之际从容地避开了这一招。\n",
        "$n身形陡然拔高，使$N的攻势尽数落空。\n",
        "$n右足一点，身影向左滑开数尺，避了开去。\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        if( me->query_skill_mapped("force") != "mystforce" )
                return notify_fail("步玄七诀必须配合步玄心法使用。\n");
	if ( me->query_skill("music") < me->query_skill("mysterrier")/2 )
		return notify_fail("你的音律之学修为不够，无法领悟更高深的步玄七诀。");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 20
        ||      (int)me->query("sen") < 20 )
                return notify_fail("你的气或神不够，不能练步玄七诀。\n");
        me->receive_damage("kee", 20);
        me->receive_damage("sen", 20);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("scholar") + "/mysterrier/" + action;
}
