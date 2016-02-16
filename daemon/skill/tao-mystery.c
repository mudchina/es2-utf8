// tao-mystery.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

void skill_improved(object me)
{
	me->add("bellicosity", 100); 
}

int practice_skill(object me)
{       
        return notify_fail("法术类技能必须用学的或是从实战中获取经验。\n");
}
