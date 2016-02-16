// lotusforce.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	if( (int)me->query_skill("buddhism") < (int)me->query_skill("lotusforce") )
		return notify_fail("你的大乘佛法修为不够，无法领会更高深的莲华心法。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("莲华心法只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
	return CLASS_D("bonze") + "/lotusforce/" + func;
}
