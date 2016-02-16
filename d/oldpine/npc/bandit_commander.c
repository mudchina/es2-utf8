// bandit_commander.c

inherit NPC;

void create()
{
	set_name("常老大", ({ "boss tsang", "boss", "tsang" }) );
	set("title", "老松寨寨主");
	set("nickname", "泼风刀王");
	set("gender", "男性");
	set("age", 53);
	set("combat_exp", 260000);
	set("score", 17000);
	set("bellicosity", 6000);
	set("attitude", "aggressive");

	set("max_force", 1000);
	set("force", 1500);
	set("force_factor", 3);

	set_skill("force", 60);
	set_skill("blade", 100);
	set_skill("parry", 100);
	set_skill("dodge", 70);

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 60);

	setup();

	carry_object(__DIR__"obj/glaive")->wield();
	carry_object(__DIR__"obj/leather")->wear();
	carry_object(__DIR__"obj/fur_coat")->wear();
	carry_object(__DIR__"obj/bamboo_pipe");
	add_money("silver", 50);
}

