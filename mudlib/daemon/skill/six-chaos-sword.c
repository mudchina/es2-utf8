// six-chaos-sword.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"群魔乱舞",
		"action":		"$N使一招「群魔乱舞」，手中$w狂风骤雨般地向$n的$l连攻数剑",
		"dodge":		50,
		"damage":		170,
		"damage_type":	"刺伤"
	]),
	([	"name":			"厉鬼缠身",
		"action":		"$N身形一转，一招「厉鬼缠身」$w斩向$n的$l",
		"dodge":		-50,
		"damage":		60,
		"damage_type":	"刺伤"
	]),
	([	"name":			"百鬼夜行",
		"action":		"$N舞动$w，一招「百鬼夜行」挟著闪闪剑光刺向$n的$l",
		"dodge":		-40,
		"damage_type":	"刺伤"
	]),
	([	"name":			"饿鬼拦路",
		"action":		"$N手中$w一抖，使出「饿鬼拦路」往$n的$l刺出一剑",
		"dodge":		-40,
		"damage":		40,
		"damage_type":	"刺伤"
	]),
	([	"name":			"鬼影幢幢",
		"action":		"$N手中$w剑光暴长，一招「鬼影幢幢」往$n$l刺去",
		"dodge":		-60,
		"damage":		120,
		"damage_type":	"刺伤"
	]),
	([	"name":			"秋坟鬼唱",
		"action":		"$N手中$w直指$n$l，一招「秋坟鬼唱」发出逼人剑气刺去",
		"dodge":		-20,
		"damage":		50,
		"damage_type":	"刺伤"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 100 )
		return notify_fail("你的内力不够，没有办法练六阴追魂剑。\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
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
	||	(int)me->query("force") < 5 )
		return notify_fail("你的内力或气不够，没有办法练习六阴追魂剑。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	write("你按著所学练了一遍六阴追魂剑法。\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
	if( (int)me->query_skill("six-chaos-sword", 1)	% 10 == 0 ) {
		tell_object(me,
			RED "\n你突然觉得一股恶气冲上心头，只觉得想杀人....\n\n" NOR);
		me->add("bellicosity", 1000);
	} else
		me->add("bellicosity", 100);
}
