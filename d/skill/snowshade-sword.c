// fonxansword.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使一招「回光幻电」，手中$w幻一条疾光刺向$n的$l",
		"dodge":		-20,
		"damae":		30,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N使出天山雪影剑中的「风霜碎影」，$w连挥剑光霍霍斩向$n的$l",
		"dodge":		-20,
		"damae":		30,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N一招「残阳照雪」，纵身飘开数尺，手中$w斩向$n的$l",
		"dodge":		-30,
		"damae":		20,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N手中$w中宫直进，一式「冰谷初虹」对准$n的$l刺出一剑",
		"dodge":		-40,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N纵身一跃，手中$w一招「长空雷隐」对准$n的$l斜斜刺出一剑",
		"dodge":		-40,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N的$w凭空一指，一招「断石狼烟」刺向$n的$l",
		"dodge":		20,
		"damage":		40,
		"damage_type":	"刺伤"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练雪影剑法。\n");

	if( (string)me->query_skill_mapped("force")!= "snowshade-force")
		return notify_fail("雪影剑法必须配合天山魔教的独门雪影心法才能练。\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");

	return 1;
}

int valid_skill_usage(string usage)
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
	||	(int)me->query("force") < 3 )
		return notify_fail("你的内力或气不够，没有办法练习雪影剑法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("你按著所学练了一遍雪影剑法。\n");
	return 1;
}
