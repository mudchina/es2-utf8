// force.c

#include <ansi.h>

inherit SKILL;

int valid_learn(object me) { return 1; }

int exert_function(object me, string arg)
{
	string func, target;
	object target_ob;

	if( sscanf(arg, "%s %s", func, target)==2 ) {
		target_ob = present(target, environment(me));
		if( !target_ob ) return notify_fail("这里没有 " + target + "。\n");
	} else 
		func = arg;
	if( file_size("/d/skill/force/" + func + ".c") < 0 )
		return notify_fail("你所学的内功\没有这种功\能。\n");
	else
		return (int)call_other("/d/skill/force/" + func, "exert", me, target_ob);
}

void skill_improved(object me)
{
	int s;

	s = me->query_skill("force", 1);
	if( s%10==9 && (int)me->query("con") < s/4) {
		tell_object(me, HIW "由于你的内功\修炼有成，你的体质改善了。\n" NOR);
		me->add("con", 2);
	}
}
