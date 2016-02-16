// girl.c

inherit NPC;

void create()
{
	set_name("柳绘心", ({ "liuh wheixin", "liuh", "wheixin" }) );
	set("gender", "女性" );
	set("age", 15);
	set("str", 16);
	set("cor", 24);
	set("cps", 11);
	set("per", 27);
	set("int", 27);

	set("attitude", "friendly");

	set("max_force", 200);
	set("force", 200);
	set("force_factor", 2);

	set("long",	"柳绘心是淳风武馆馆主柳淳风的独生女。\n");

	create_family("封山剑派北宗", 14, "弟子");

	set("combat_exp", 1000);

	set("chat_chance_combat", 25);
	set("chat_msg_combat", ({
		(: perform_action, "sword.counterattack" :),
		"柳绘心秀眉微蹙，说道：喂！我哪里得罪你了？干嘛这样跟我拼死拼活？\n",
		"柳绘心不住地望著窗外：你还是快走吧，我没空陪你练功\夫！\n",
	}) );

	set_skill("unarmed", 20);
	set_skill("parry", 40);
	set_skill("dodge", 50);
	set_skill("sword", 30);
	set_skill("force", 30);
	set_skill("literate", 70);

	set_skill("fonxanforce", 40);
	set_skill("fonxansword", 40);
	set_skill("liuh-ken", 40);
	set_skill("chaos-steps", 70);

	map_skill("unarmed", "liuh-ken");
	map_skill("sword", "fonxansword");
	map_skill("parry", "fonxansword");
	map_skill("dodge", "chaos-steps");

	setup();

	carry_object(__DIR__"obj/thin_sword")->wield();
	carry_object(__DIR__"obj/pink_cloth")->wear();
	carry_object(__DIR__"obj/shoe")->wear();
}

int accept_fight(object me)
{
	if( (string)me->query("family/family_name")=="封山剑派" ) {
		if( (string)me->query("gender")=="女性" ) {
			command("say 师姐！别整天想著练功\嘛，我们去花园摘花儿玩嘛？");
			return 0;
		} else {
			command("say 我才不要，你们去找李教头练吧！");
			return 0;
		}
	}
	command("say 爹爹说过，不能跟你们这些江湖人物比武过招。");
	return 0;
}
