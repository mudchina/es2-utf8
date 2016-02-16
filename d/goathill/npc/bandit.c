// bandit.c

inherit NPC;

void create()
{
	set_name("土匪爪牙", ({ "bandit minion", "bandit", "minion" }) );
	set("gender", "男性");
	set("age", 26);
	set("long",
		"一个眼神凶恶的土匪，脸上好几条长长的刀疤，看起来就知道不好惹。\n");
	set("combat_exp", 6000);
	set("attitude", "aggressive");
	set_skill("blade", 40);
	set_skill("parry", 40);
	set_skill("dodge", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 30);
	setup();
	carry_object(__DIR__"obj/steel_blade")->wield();
	add_money("silver", 10);
}
