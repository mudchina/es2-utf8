// bandit.c

inherit NPC;

void create()
{
	set_name("土匪首领", ({ "bandit leader", "bandit", "leader" }) );
	set("gender", "男性");
	set("age", 31);
	set("long",
		"这个土匪看起来相当强悍，至少你从他的动作就可以看得出来他显然\n"
		"是练过武功\的硬手，并不是泛泛之辈。\n");
	set("combat_exp", 14000);
	set("attitude", "aggressive");
	set_skill("axe", 70);
	set_skill("parry", 60);
	set_skill("dodge", 70);
	set_temp("apply/attack", 60);
	set_temp("apply/defense", 80);
	setup();
	carry_object(__DIR__"obj/hand_axe")->wield();
	carry_object(__DIR__"obj/hand_axe")->wield();
	add_money("silver", 10);
}
