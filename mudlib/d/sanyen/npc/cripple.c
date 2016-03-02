// cripple_bonze.c

inherit NPC;

void create()
{
	set_name("跛僧人", ({ "cripple bonze", "bonze" }) );
	set("gender", "男性" );
	set("class", "bonze");
	set("age", 36);
	set("str", 26);
	set("cor", 24);
	set("cps", 12);
	set("int", 20);
	set("long", "这个僧人跛了右腿，脸上没有什么表情，一副若有所思的样子。\n");
	set("combat_exp", 4000);
	set("attitude", "friendly");

	set("max_force", 1300);
	set("force", 1300);
	set("force_factor", 3);

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: random_move :),
		(: command, "sigh" :)
	}) );

	set_skill("force", 90);
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("buddhism", 60);
	set_skill("lotusforce", 90);

	map_skill("force", "lotusforce");

	setup();

	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/shoe")->wear();
}

int accept_fight(object me)
{
	command("say 阿弥陀佛！贫僧武功\低微，又是个残废，施主不要开这种玩笑。\n");
	return 0;
}
