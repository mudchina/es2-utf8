// music. 

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{
        int s;

        s = me->query_skill("music", 1);
        if( s%10==9 && (int)me->query("spi") < s/4) {
                tell_object(me, HIW
"由於你学习音律之学有成，你的灵性提高了\n" NOR);
                me->add("spi", 2);
        }
}

