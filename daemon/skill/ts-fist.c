// ts-first.c
//天山折梅手

inherit SKILL;

mapping *action = ({
	([	"action":		"$N左掌轻动右手向上一探一招「梅影疏斜」抓向$n的$l，姿态美妙",
		"dodge":		-30,
		"parry":		-70,
		"force":		210,
		"damage_type":	"抓伤"
	]),
	([	"action":		"$N倏地一个转身双手一送「梅香袭人」直銎$n$l",
		"dodge":		-10,
		"parry":		-60,
		"force":		190,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N身子微斜随即跨出一步右手一划使出「踏雪寻梅」拍向$n的$l",
		"dodge":		-30,
		"parry":		-40,
		"force":		110,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N双手一抖「老梅虬枝」从一个匪夷所思的角度对准$n的$l抓去",
		"dodge":		10,
		"parry":		-60,
		"force":		190,
		"damage_type":	"抓伤"
	]),
	([	"action":		"$N左手虚晃右掌飘飘一招「映雪红梅」击向$n$l",
		"dodge":		-20,
		"parry":		-50,
		"force":		250,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N使出「梅凋无声」凌空跃起冷不防在落地前对准$n$l拍出一掌",
		"dodge":		-70,
		"parry":		-40,
		"force":		180,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N右手在$n$l划过随後一招「梅妻鹤子」左手又向同一方位抓到",
		"parry":		-90,
		"force":		150,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N右手连摇左手使出「暗香浮动」，波的一声击向$n的$l",
		"parry":		-90,
		"force":		360,
		"damage_type":	"瘀伤"
	]),

});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练天山折梅手必须空手。\n");
	if( (int)me->query("max_force") < 80 )
		return notify_fail("你的内力太弱无法练天山折梅手。\n");
	return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 25 )
		return notify_fail("你的体力不够了休息一下再练吧。\n");
	if( (int)me->query("force") < 3 )
		return notify_fail("你的内力不够了休息一下再练吧。\n");
	me->receive_damage("kee", 25);
	me->add("force", -3);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/2) > victim->query_str() ) {
		victim->receive_wound("kee", (damage_bonus - 80) / 2 );
		switch(random(5)) {
			case 0: return "你听到「喀啦」一声轻响竟似是骨碎的声音ⅵ\n";
			case 1: return "$N劲力一吐$n的$l发出「喀」地一声爆响ⅵ\n";
			case 2: return "只听见$n的$l「喀」地一声 ...\n";
			case 3: return "$N的双手如同一条活鱼一样，迅捷无伦地击中$n的$l！\n";
			case 4: return "天山折梅手果然名不虚传，$n的$l立刻被印上一记！\n";
		}
	}
}

