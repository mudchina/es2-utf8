// phantomforce.c

inherit ITEM;

void create()
{
	set_name("域摩经", ({ "book" }));
	set_weight(600);
	set("unit", "本");
	set("long",
		"这是魔道修炼者梦寐以求的内功\秘诀「地灵心法」，书中记载了逆天而\n"
		"生、反转五行生克与内脏的心法。\n");
	set("value", 100);
	set("skill", ([
		"name": 		"phantomforce",	// name of the skill
		"exp_required":	1000000,		// minimum combat experience required
										// to learn this skill.
		"gin_cost":		30,				// gin cost every time study this
		"difficulty":	30,				// the base int to learn this skill
										// modify is gin_cost's (difficulty - int)*5%
		"max_skill":	40				// the maximum level you can learn
										// from this object.
	]) );
}
