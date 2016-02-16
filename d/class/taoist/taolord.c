// taolord.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("林忌", ({ "master taolord", "master", "taolord" }) );
	set("nickname", "六指真人");
	set("gender", "男性");
	set("age", 47);
	set("long",
		"林忌是一位道行十分高深的修道者，你发现他的眼珠一个是黑色的，一\n"
		"个是金色的，这正是「谷\衣心法」修炼到极高境界的徵兆。\n");

	set("combat_exp", 1000000);
	set("score", 200000);

	set("class", "taoist");

	set("str", 20);
	set("int", 30);
	set("cor", 20);
	set("cps", 30);
	set("spi", 30);

	set("force", 700);
	set("max_force", 700);
	set("force_factor", 3);

	set("atman", 1400);
	set("max_atman", 1400);

	set("mana", 2000);
	set("max_mana", 2000);
	set("mana_factor", 5);

	set("inquiry", ([
		"谷\衣心法": "谷\衣心法是我茅山派为对抗邪魔外道所创的内功\心法。\n",
		"茅山派": "我茅山派自张天师开山立派至今，世世代代皆以降妖伏魔为己任。\n"
	]) );

	set("apprentice_available", 3);
	set("chat_chance", 80);
	set("chat_msg_combat", ({
		(: cast_spell, "drainerbolt" :),
		(: cast_spell, "netherbolt" :),
		(: cast_spell, "feeblebolt" :),
		(: cast_spell, "invocation" :),
	}) );

	create_family("茅山派", 5, "天师");

	set_skill("literate", 70);
	set_skill("magic", 80);
	set_skill("force", 30);
	set_skill("spells", 100);
	set_skill("scratching", 100);
	set_skill("unarmed", 30);
	set_skill("sword", 40);
	set_skill("parry", 40);
	set_skill("dodge", 40);
	set_skill("gouyee", 60);

	set_skill("taoism", 100);
	set_skill("necromancy", 100);

	map_skill("magic", "taoism");
	map_skill("spells", "necromancy");

	set_temp("apply/dodge", 20);
	set_temp("apply/armor", 20);

	setup();

	carry_object(__DIR__"sword")->wield();
	carry_object(__DIR__"robe")->wear();
	carry_object(__DIR__"hat")->wear();
	carry_object(__DIR__"shoe")->wear();
}

void attempt_apprentice(object ob)
{
	if( query("apprentice_available") ) {
		if( find_call_out("do_recruit") != -1 )
			command("say 慢著，一个一个来。");
		else
			call_out("do_recruit", 2, ob);
	} else {
		command("say 贫道今天已经收了三个弟子，不想再收徒了。");
	}
}

void do_recruit(object ob)
{
	if( (string)ob->query("gender") != "男性" )
		command("say 贫道是出家人，不便收女徒，得罪了。");
	else {
		command("say 嗯... 想入我茅山派？也好....");
		command("recruit " + ob->query("id") );
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "taoist");
	add("apprentice_availavble", -1);
}

