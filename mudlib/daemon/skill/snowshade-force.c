// snowshade-force.c

inherit FORCE;

void create() { seteuid(getuid()); }

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("天山雪影心法只能用学的或是从运用(exert)中增加熟练度。\n");
} 
