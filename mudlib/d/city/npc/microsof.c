// microsof.c
#include <ansi.h>

inherit NPC;

string ask_me(object who); 

void create()
{
	set_name("黑你没商量", ({ "microsof" }) );
	set("title", "钱庄老板");
	set("gender", "男性" );
	set("age", 30);

	set("str", 22);
	set("cor", 25);
	set("cps", 25);
	set("int", 26);
	set("per", 25);
	set("con", 24);
	set("spi", 25);
	set("kar", 25);

	set("long",
		"黑你没商量是个看起来相当精明的中年人，他的本名叫做“魏阮”。\n"
		"不知作了什么黑心的生意，一夜之间暴富起来，开了钱庄后，逐渐地\n"
		"把其它钱庄全挤倒闭了，京师的居民对他的很多做法都非常不满，于\n"
		"是有了这个绰号。大家都知道他小肚鸡肠，所以谁也不去惹他。\n");

	set("combat_exp", 100000);
	set("attitude", "friendly");
	set("pursuer", 1);
	set("env/wimpy", 70);

	set("max_atman", 1000);		set("atman", 1000);		set("atman_factor", 3);
	set("max_force", 1000);		set("force", 1000);		set("force_factor", 3);
	set("max_mana", 1000);		set("mana", 1000);		set("mana_factor", 3);

	set("chat_chance", 15 );
	set("chat_msg", ({
		CYN "黑你没商量压低嗓音对你说道：“我在上面可有人，你知道我每年给上面多少金子吗？”\n"
 NOR,
		CYN "黑你没商量恨恨地说：“哼，我要把NT也汉化，看你之星怎么办！”\n" NOR,
		(: exert_function, "powerfade" :),
		}) );

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		CYN "黑你没商量突然三角眼倒立，眉间闪过几道黑气。\n" NOR,
		CYN "黑你没商量的喉咙发出咕咕两声怪叫。\n" NOR,
		CYN "黑你没商量神情忽然严肃了起来，不过好像是在想自己的事，与你无关。\n" NOR,
		CYN "黑你没商量忽然呵呵呵地笑了起来，却不知道在笑些什么....\n" NOR,
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

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
			say( "黑你没商量一翻三角眼，不知又想出了什么坏主意。\n");
			break;
		case 1:
			say( "黑你没商量说道：这位" + RANK_D->query_respect(ob)
			 + "，换钱？我要抽点的啊！\n");
			break;
		case 2:
			say( "黑你没商量说道：这位" + RANK_D->query_respect(ob)
			 + "，钱可要自己点清楚啊！\n");
			break;
	}
}

int accept_fight(object me)
{
	command("say 咦... 要打就真打吧，光是较量多没意思？");
	command("grin");
	kill_ob(me);
	return 1;
}
