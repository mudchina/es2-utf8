// fonxanforce.c

inherit SKILL;

void create() { seteuid(getuid()); }

int valid_skill_usage(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
	return notify_fail("封山派内功\只能用学的或是从运用(exert)中增加熟练度。\n");
}