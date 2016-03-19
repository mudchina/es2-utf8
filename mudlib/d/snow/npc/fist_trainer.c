// trainer.c

inherit NPC;

void create()
{
	set_name("李火狮", ({ "trainer", "lee" }) );
	set("title", "拳法教练");
	set("gender", "男性" );
	set("age", 28);
	set("str", 26);
	set("int", 14);
	set("long",
		"李火狮是个孔武有力的大块头，他正在训练他的弟子们习练「柳家拳\n"
		"法」。\n" );
	set("combat_exp", 3000);
	set("attitude", "heroism");

	set("force", 120);
	set("max_force", 120);
	set("force_factor", 1);

	set("inquiry", ([
		"here": "这里当然是淳风武馆，不然还是哪里？\n",
		"name": "在下姓李，名字就叫火狮，人称李教头的便是我。\n",
		"柳家拳法": "哦....说来惭愧，小弟这套拳法还没学得到家, 柳馆主就教我在这里传艺。\n"
	]) );

	set_skill("unarmed", 30);
	set_skill("liuh-ken", 20);
	set_skill("dodge", 30);
	map_skill("unarmed", "liuh-ken");

	setup();
}

int recognize_apprentice(object ob)
{
	if( (string)ob->query("family/family_name")=="封山剑派" ) return 1;
	command("say 对不起，这位" + RANK_D->query_respect(ob) + "，您不是我们武馆的弟子。");
	return notify_fail( "李火狮不愿意教你拳法。\n");
}

int accept_fight(object me)
{
	if( (string)me->query("family/family_name")=="封山剑派" ) {
		command("nod");
		command("say 进招吧。");
		return 1;
	}
	command("say 馆主吩咐过，不许和来这里的客人过招。");
	return 0;
}
