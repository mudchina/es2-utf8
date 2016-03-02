// necromancy.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_skill_usage(string usage) { return usage=="spells"; }

int valid_learn(object me) { return 1; }

int cast_spell(object me, string arg)
{
	string spl, trg;
	object target;

	if( sscanf(arg, "%s %s", spl, trg)==2 )	{
		if( !objectp(target = present(trg, environment(me))) )
			return notify_fail("你要对谁施展这个法术？\n");
	} else {
		spl = arg;
		target = 0;
	}
	if( file_size(__DIR__"necromancy/" + spl + ".c")<=0 )
		return notify_fail("茅山道术之中没有这种法术。\n");

	notify_fail("这种法术不能直接施展。\n");
	return (int)call_other(__DIR__"necromancy/" + spl, "cast_spell", me, target);
}

int scratch_spell(object me, object sheet, string arg)
{
	string spl, trg;
	object target;

	if( !arg || sscanf(arg, "%s %s", spl, trg)!=2 ) {
		spl = arg;
		trg = 0;
	}

	if( file_size(__DIR__"necromancy/" + spl + ".c")<=0 )
		return notify_fail("茅山道术之中没有这种符咒。\n");

	notify_fail("这种法术并没有画成符咒的方法。\n");

	return (int)call_other(__DIR__"necromancy/" + spl, "scratch_spell", me, sheet, trg);
}

int practice_skill(object me)
{	
	object bug;

	if( bug = me->query_temp("mind_bug") )
		return notify_fail("你的魂魄还没有全部收回，赶快杀死你的"
			+ bug->name() + "吧！\n");

	if( (int)me->query("mana") < 10 )
		return notify_fail("你的法力不够。\n");

	if( (int)me->query("sen") < 30 )
		return notify_fail("你的精神无法集中。\n");

	me->add("mana", -10);
	me->receive_damage("sen", 30);

	write("你闭目凝神，神游物外，开始修习茅山道术中的法术....\n");
	if( random((int)me->query("sen")) < 5 ) {
		int rnd;

		rnd = random(me->query_skill("spells", 1));
		if( rnd < 10 )	bug = new("/obj/npc/mind_bug");
		else			bug = new("/obj/npc/mind_beast");

		write("可是你心思一乱，变出了一只面目狰狞的" + bug->name() + "！\n");
		bug->move(environment(me));
		bug->kill_ob(me);
		me->fight(bug);
		me->set_temp("mind_bug", bug);
		bug->set("owner", me->query("id"));
		return notify_fail("你的魂魄正被" + bug->name() + "缠住，快把它除掉吧！\n");
	}	
	else return 1;
}
