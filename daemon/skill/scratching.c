
#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "三清归真",
                "action":               "$N一招「三清归真」，手中$w挽起几个剑花，刺向$n的$l",
                "dodge":                -40,
                "damage":               40,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "众士护佑",
                "action":               "$N身形一变，一招「众士护佑」，$w罩向$n的$l",
                "dodge":                -50,
                "damage":               30,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "天人合一",
                "action":               "$N挥动$w，一招「天人合一」挟著闪闪剑光袭向$n的$l",
                "dodge":                -40,
		"damage":		50,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "群魔辟易",
                "action":               "$N手中$w一抡，使出「群魔辟易」往$n的$l恶狠狠的砍去",
                "dodge":                -40,
                "damage":               40,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "西出紫关",
                "action":               "$N一招「西出紫关」，$w一带，轻轻划向$n$l",
                "dodge":                -60,
                "damage":               20,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "乾坤一掷",
                "action":               "$N身剑合一，幻化成一道光华，一招「乾坤一掷」扑向$n",
                "dodge":                50,
                "damage":               150,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 80 )
                return notify_fail("你的内力不够，没有办法练天师剑法。\n");

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
        object ob;

	if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习天师剑法。\
");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按著所学练了一遍天师剑法。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}


