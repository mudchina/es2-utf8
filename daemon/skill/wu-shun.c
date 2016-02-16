// wu-shun.c
// 小无相功
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	if( (int)me->query_skill("literate") < (int)me->query_skill("wu-shun") )
		return notify_fail("你的文学素养不够无法提升小无相功的造诣。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("小无相功只能用学的或是从运用(exert)中增加熟练度。\n");
}

//string exert_function_file(string func)
//{
//	return CLASS_D("xiaoyao") + "/wu-shun/" + func;
//}

