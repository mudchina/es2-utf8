// snowwhip.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"寒风起兮",
		"action":		"$N使一招「寒风起兮」，手中$w抖得笔直向$n的$l连刺数鞭",
		"dodge":		-10,
		"damage":		30,
		"damage_type":	"刺伤"
	]),
	([	"name":			"漫天飞雪",
		"action":		"$N身形一转，一招「漫天飞雪」$w幻出满天鞭影，虚虚实实地袭向$n的$l",
		"dodge":		-50,
		"damage":		20,
		"damage_type":	"瘀伤"
	]),
	([	"name":			"雪花翩翩",
		"action":		"$N力贯$w，一招「雪花翩翩」点点鞭影飘浮不定地点向$n的$l",
		"dodge":		-40,
		"damage":		25,
		"damage_type":	"刺伤"
	]),
	([	"name":			"积雪三尺",
		"action":	        "$N手中$w一抖，一招「积雪三尺」以一个怪异的角度往$n下盘卷去",
		"dodge":		-40,
		"damage":		30,
		"damage_type":	"瘀伤"
	]),
        ([
		"name":			"狂风骤雪",
		"action":		"$N手中一紧，使招「狂风骤雪」，手里$w一鞭接著一鞭不停地抽向$n的$l",
		"dodge":		-50,
		"damage":		100,
		"damage_type":   "鞭伤"
        ]),
	([	"name":			"风雪交加",
		"action":		"$N一招「风雪交加」手中$w舞出一片鞭影扫向$n全身",
		"dodge":		-60,
		"damage":		150,
		"damage_type":	"瘀伤"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 150 )
		return notify_fail("你的内力不够，没有办法练寒雪鞭法, 多练些内力再来吧。\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "whip" )
		return notify_fail("你必须先找一条鞭子才能练鞭法。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="whip";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 5 )
		return notify_fail("你的内力或气不够，没有办法练习寒雪鞭法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	write("你按著所学练了一遍寒雪鞭法。\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

