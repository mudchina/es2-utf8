// magic-array.c

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("tao-mystery") <= (int)me->query_skill("magic-array"))
                return notify_fail("你的小天魔道修为不够，无法领悟更高深的奇门遁甲之术。\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("juechen") + "/magic-array/" + spell;
}

int practice_skill(object me)
{
        return notify_fail("法术类技能必须用学的或是从实战中获取经验。\n");
}

