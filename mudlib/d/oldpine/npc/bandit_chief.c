// bandit_chief.c

inherit NPC;

void create()
{
	set_name("土匪老大", ({ "bandit chief", "chief" }) );
	set("gender", "男性");
	set("age", 39);
	set("long",
		"这家伙眼神凶恶，一双精光四射的眼珠正盯著你的脖子。\n");
	set("combat_exp", 6000);
	set("score", 700);
	set("attitude", "aggressive");
	set("chat_chance", 10);
	set("chat_msg_combat", ({
		"\n土匪老大阴恻恻地说道：乖乖地躺下吧！\n",
		"\n土匪老大说道：自从刘老三洗手不干以后，只怕这附近还没有我的对手！\n",
		"\n土匪老大虎吼一声，欺身上前。\n"
	}) );
	set_skill("blade", 60);
	set_skill("parry", 50);
	set_skill("dodge", 50);

	// Because the chief's 武功 is not done yet, set apply to replace it.
	set_temp("apply/attack", 50);
	set_temp("apply/dodge", 30);

	setup();
	carry_object(__DIR__"obj/blade")->wield();
	carry_object(__DIR__"obj/leather")->wear();
	add_money("silver", 30);
}

void start_help()
{
	say("一条人影从树林间跃出，身手矫健，显是武功\不弱。\n");
	command("say 哈哈哈... 连这几个小角色也打发不了，站开一点！\n");
}
