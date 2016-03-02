// taoism.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
        if( (int)me->query("bellicosity") > 100 )
                return notify_fail("你的杀气太重，无法修炼天师正道。\n");
        return 1;
}

int practice_skill(object me)
{       
        return notify_fail("法术类技能必须用学的或是从实战中获取经验。\n");
}
