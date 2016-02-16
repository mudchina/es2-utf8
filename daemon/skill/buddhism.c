// buddhism.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	if( (int)me->query("bellicosity") > 100 )
		return notify_fail("你的杀气太重，无法修炼大乘佛法。\n");
	return 1;
}

