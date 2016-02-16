// master.c

inherit NPC;

void create()
{
	set_name("蓝止萍", ({ "master dancer", "master", "dancer" }) );

	set("title", "晚月庄主");
	set("nickname", "回音仙子");
	set("gender", "女性");
	set("age", 22);
	set("long",
		"蓝止萍是一个十分出色的美女，她弹的一手琵\琶更是闻名千里，许\多\n"
		"王侯子弟，富商豪客都为她天下无双的美貌与琴艺倾倒。\n");
	set("attitude", "peaceful");
	set("class", "dancer");
	set("apprentice_available", 10);

	set("str", 21);
	set("int", 28);
	set("spi", 26);
	set("per", 30);

	set("force", 600);
	set("max_force", 600);

	set("combat_exp", 1000000);
	set("score", 9000);

	set_skill("unarmed", 40);
	set_skill("sword", 70);
	set_skill("throwing", 100);
	set_skill("force", 30);
	set_skill("parry", 70);
	set_skill("dodge", 100);
	set_skill("literate", 100);
	set_skill("perception", 100);

	create_family("晚月庄", 1, "庄主");

	setup();

	carry_object(__DIR__"echowhip")->wield();
	carry_object(__DIR__"snake_sandal")->wear();
	carry_object(__DIR__"gold_belt")->wear();
	carry_object(__DIR__"bloody_dress")->wear();
}

void reset()
{
	delete_temp("learned");
	set("apprentice_available", 10);
}

int prevent_learn(object me, string skill)
{
	if( (int)query_temp("learned/" + me->query("id")) > 15 ) {
		command("say 我说" + me->name(1) + "啊，不要老是待在师父身边，出去磨练磨练吧。\n");
		return 1;
	} else
		add_temp("learned/" + me->query("id"), 1);
}

void attempt_apprentice(object ob)
{
	if( query("apprentice_available") ) {
		if( find_call_out("do_recruit") != -1 )
			command("say 慢著，一个一个来。");
		else
			call_out("do_recruit", 2, ob);
	} else {
		command("say 本庄主今天已经收了十个弟子，不想再收徒了。");
	}
}

void do_recruit(object ob)
{
	if( (string)ob->query("gender") != "女性" )
		command("say 男人都不是好东西，滚开！");
	else {
		command("say 很好，只要你对本庄主忠心耿耿，好处是少不了的。");
		if( (int)ob->query("per") > 25 && (int)ob->query("age") < 20 )
			message_vision("$N暧昧地抚摸著$n的脸，说道：特别是像你这样的女孩....\n", this_object(), ob);
		command("recruit " + ob->query("id") );
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "dancer");
	add("apprentice_availavble", -1);
}
