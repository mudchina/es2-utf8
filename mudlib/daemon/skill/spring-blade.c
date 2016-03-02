// spring-blade.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使一招「春风拂人醉」，手中$w轻飘飘地向$n的$l斩去！",
		"damage":		200,
		"dodge":		70,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N金刃劈风，$w随著一招「远山伴人痴」由下而上撩往$n的$l",
		"damage":		40,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N身形一转，一招「飞花逐人香」$w刀光不定，斩向$n的$l",
		"damage":		20,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N舞动$w，一招「柳叶随人笑」迅捷无伦地劈向$n的$l",
		"damage_type":	"□伤"
	]),
	([	"action":		"$N手中$w一晃，一招「倩影惹人怜」往$n的$l斜斜砍出一刀",
		"damage":		40,
		"damage_type":	"□伤"
	]),
	([	"action":		"$N提刀过肩，蓄劲发力，一招「芦雪碎人影」直劈$n$l",
		"damage":		40,
		"damage_type":	"□伤"
	]),
	([	"action":		"$N移步侧身，使一招「彩蝶灼人衣」刀光霍霍斩向$n的$l",
		"damage":		40,
		"damage_type":	"□伤"
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
	||	(string)weapon->query("skill_type") != "blade" )
		return notify_fail("你必须先找一把刀，才能练刀法。\n");

	if( (int)me->query("kee") < 40 )
		return notify_fail("你的体力不够练这门刀法，还是先休息休息吧。\n");
	me->receive_damage("kee", 40);
	return 1;
}
