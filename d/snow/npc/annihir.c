// banker.c

#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
	set_name("安惜迩", ({ "annihir" }) );
	set("title", "钱庄老板");
	set("gender", "男性" );
	set("age", 26);

	set("str", 22);
	set("cor", 30);
	set("cps", 30);
	set("int", 26);
	set("per", 23);
	set("con", 24);
	set("spi", 30);
	set("kar", 25);

	set("long",
		"安惜迩是个看起来相当斯文的年轻人，不过有时候会有些心不在焉的\n"
		"样子，雪亭镇的居民对安惜迩都觉得有点神秘莫测的感觉，为什么他\n"
		"年纪轻轻就身为一家大钱庄的老板，还有他一身稀奇古怪的武功\，所\n"
		"幸安惜迩似乎天性恬淡，甚至有些隐者的风骨，只要旁人不去惹他，\n"
		"他也绝不会去招惹旁人。\n");

	set("combat_exp", 200000);
	set("attitude", "friendly");
	set("pursuer", 1);
	set("env/wimpy", 70);

	set("max_atman", 1000);		set("atman", 1000);		set("atman_factor", 3);
	set("max_force", 1000);		set("force", 1000);		set("force_factor", 3);
	set("max_mana", 1000);		set("mana", 1000);		set("mana_factor", 3);

	set("chat_chance", 15 );
	set("chat_msg", ({
//		(: random_move :),
		(: exert_function, "powerfade" :),
	}) );

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		CYN "安惜迩似笑非笑地望著你，脸上的神气古理古怪，不知道在想些什么？\n" NOR,
		CYN "安惜迩的身影晃了一下，似乎在你身上各处大穴摸了一下，不过也许\是你的错觉。\n" NOR,
		CYN "安惜迩神情忽然严肃了起来，不过好像是在想自己的事，与你无关。\n" NOR,
		CYN "安惜迩忽然呵呵呵地笑了起来，却不知道在笑些什么....\n" NOR,
		(: perform_action, "sword.counterattack" :),
		(: cast_spell, "drainerbolt" :),
		(: cast_spell, "feeblebolt" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );

	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("force", 100);
	set_skill("celestrike", 100);
	set_skill("celestial", 100);
	set_skill("fonxansword", 100);
	set_skill("six-chaos-sword", 100);
	set_skill("chaos-steps", 100);
	set_skill("spells", 100);
	set_skill("necromancy", 100);

	map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");
	map_skill("dodge", "chaos-steps");
	map_skill("sword", "fonxansword");
	map_skill("spells", "necromancy");
	map_skill("sword", "fonxansword");
	
	setup();
	
	carry_object("/obj/longsword")->wield();
	carry_object("/obj/cloth")->wear();

	add_money("gold", 10);
}

int accept_fight(object me)
{
	command("say 咦... 要打就真打吧，光是较量多没意思？");
	command("grin");
	kill_ob(me);
	return 1;
}
