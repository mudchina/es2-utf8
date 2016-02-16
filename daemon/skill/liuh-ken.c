// liuh-ken.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使一招「古松挂月」，对准$n的$l「呼」地一拳",
		"dodge":		-40,
		"parry":		40,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N扬起拳头，一招「傲雪冬梅」便往$n的$l招呼过去",
		"dodge":		-30,
		"parry":		30,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N左手虚晃，右拳「孤崖听涛」往$n的$l击出",
		"dodge":		-30,
		"parry":		30,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N步履一沉，左拳拉开，右拳使出「荒山虎吟」击向$n$l",
		"dodge":		-30,
		"parry":		30,
		"damage_type":	"瘀伤"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练柳家拳法必须空手。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	me->receive_damage("kee", 30);
	return 1;
}
