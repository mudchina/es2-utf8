// linbo-step.c
//凌波微步

inherit SKILL;

string *dodge_msg = ({
	"$n一招「瞻忽在前」轻轻松松地避了开去。\n",
	"只见$n身形一转一式「动若脱兔」早已闪开$N的攻击。\n",
	"$n使出「微尘不惊」身形微动，$N又扑了个空。\n",
	"$n左足一退右足一分，一招「若有若无」已避了开去。\n",
	"可是$n使一招「姑射仙人」身子象轻纱一样飘了开去。\n",
	"$n下身不动，上身轻侧已经藉一招「静若处子」轻轻闪过。\n",
	"但是$n一招「瞻忽在后」使出竟然绕到$N身後！\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query_skill("literate", 1) < 60 )
		return notify_fail("你的文学素养不够没有办法练凌波微步。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("gin") < 80
	||	(int)me->query("sen") < 80 )
		return notify_fail("你的精神不足不能练凌波微步。\n");
	me->receive_damage("gin", 10);
	me->receive_damage("sen", 10);
	me->add("force", 3);
	return 1;
}

