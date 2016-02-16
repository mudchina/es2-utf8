// maniac.c

inherit NPC;

void create()
{
	object ob;

	set_name("疯老头子", ({ "mad bad ugly dirty oldman", "man", "oldman" }) );
	set("gender", "男性");
	set("age", 67);
	set("long",
		"这个老头子正对著你龇牙裂嘴，他看起来已经完全疯了。\n");

	set("str", 30);
	set("cor", 30);
	set("combat_exp", 40000);
	set("score", 8000);
	set("bellicosity", 10000);

	set("force", 600);
	set("max_force", 600);
	set("force_factor", 2);

	set("mana", 800);
	set("max_mana", 800);

	set_skill("unarmed", 50);
	set_skill("dodge", 70);
	set_skill("force", 100);
	set_skill("spells", 50);
	set_skill("necromancy", 70);
	map_skill("spells", "necromancy");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: cast_spell, "netherbolt" :),
		(: cast_spell, "feeblebolt" :),
		(: cast_spell, "drainerbolt" :)
	}) );

	// These temp apply are intended for beast race. If you want apply
	// to a human, need some good reason. For this example, this oldman
	// is a maniac, go can apply some extra attack bonus and damage.
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 20);

	setup();

	carry_object(__DIR__"obj/robe.c")->wear();
}
