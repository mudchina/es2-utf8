// pyrobat-steps.c

inherit SKILL;

/* string *dodge_msg = ({
	"但是$n身形飘忽，轻轻一纵，早已避开。\n",
	"$n身随意转，倏地往一旁挪开了三尺，避过了这一招。\n",
	"可是$n侧身一让，$N这一招扑了个空。\n",
	"却见$n足不点地，往旁窜开数尺，躲了开去。\n",
	"$n身形微晃，有惊无险地避开了$N这一招。\n"
});
*/

string *dodge_msg = ({
	"可是$p侧身一让，使出「寒蝠掠江」，$N这一招扑了个空。\n",
	"$p身形微晃，使出「灵蝠轻逝」，有惊无险地避开了$N这一招。\n",
	"$p身随意转，一式「轻蝠点梢」，倏地往一旁挪开了三尺，避过了这一招。\n",
	"却见$p足不点地，一招「夜蝠旋身」，往旁窜开数尺，躲了开去。\n",
	"只见$p一招「火蝠曳空」，身形向上拔起数尺高，闪了过去。\n"
});
int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("你的体力太差了，不能练火蝠身法。\n");
	me->receive_damage("kee", 30);
	return 1;
}
