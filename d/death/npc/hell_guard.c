// hell_guard.c

inherit NPC;

void create()
{
	string *order = ({"子", "丑", "寅", "卯", "辰", "巳", "午", "未", "申", "酉", "戌", "亥"});

	set_name( (order[random(12)]) + "阴鬼牙将", ({ "hell guardian", "guardian" }) );
	set("long",
		"一个负责看守鬼门关的阴卒，他们是鬼卒中的精锐，负责阻挡想要\n"
		"侵入酆都城的妖魔鬼怪。\n");

	set("max_gin", 1500);
	set("max_kee", 1500);
	set("max_sen", 1500);

	set("max_atman", 900);
	set("atman", 900);
	set("max_mana", 900);
	set("mana", 900);

	set("str", 50);
	set("cor", 50);
	set("cps", 50);

	set("combat_exp", 400000);

	set("vendetta_mark", "hell");

	set_skill("fork", 100);
	set_skill("parry", 90);
	set_skill("dodge", 90);

	set_temp("apply/attack", 75);
	set_temp("apply/defense", 75);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 50);
	setup();

	carry_object(__DIR__"obj/hell_armor")->wear();
	carry_object(__DIR__"obj/fork")->wield();
}

int is_ghost() { return 1; }
