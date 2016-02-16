// blade_book.c

inherit ITEM;

void create()
{
	set_name("残破刀谱", ({ "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
			"这似乎是一本什么刀谱的前几页，虽然并没有关于招式的详细解说，可是\n"
			"前面有关刀法的总纲与精义倒是不少。\n");
		set("value", 260);
		set("material", "paper");
		set("skill", ([
			"name": 		"blade",		// name of the skill
			"exp_required":	1000,			// minimum combat experience required
											// to learn this skill.
			"sen_cost":		30,				// gin cost every time study this
			"difficulty":	20,				// the base int to learn this skill
											// modify is gin_cost's (difficulty - int)*5%
			"max_skill":	40				// the maximum level you can learn
											// from this object.
		]) );
	}
}
