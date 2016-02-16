// master.c

inherit NPC;

void create()
{
	set_name("玄智和尚", ({ "master bonze", "master", "bonze" }) );

	set("gender", "男性");
	set("age", 74);
	set("attitude", "peaceful");
	set("class", "bonze");
	set("apprentice_available", 10);

	set("str", 17);
	set("int", 30);
	set("spi", 30);
	set("con", 30);

	set("atman", 2000);
	set("max_atman", 2000);

	set("force", 1500);
	set("max_force", 1500);
	set("force_factor", 5);

	set("mana", 600);
	set("max_mana", 600);

	set("combat_exp", 1000000);
	set("score", 9000);

	set_skill("unarmed", 80);
	set_skill("force", 100);
	set_skill("dodge", 30);
	set_skill("literate", 60);

	create_family("山烟寺", 26, "住持");

	setup();
}

void attempt_apprentice(object ob)
{
	if( query("apprentice_available") ) {
		if( find_call_out("do_recruit") != -1 )
			command("say 慢著，一个一个来。");
		else
			call_out("do_recruit", 2, ob);
	} else {
		command("say 老纳今天已经收了十个弟子，不想再收徒了。");
	}
}

void do_recruit(object ob)
{
	if( (string)ob->query("gender") != "男性" )
		command("say 阿弥陀佛，女施主不要跟老纳开玩笑。");
	else if( (string)ob->query("class") != "bonze" )
		command("say 阿弥陀佛，施主愿入佛门，请先到小寺剃度出家。");
	else {
		command("say 阿弥陀佛，善哉！善哉！");
		command("recruit " + ob->query("id") );
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) ) {
		add("apprentice_availavble", -1);
		return 1;
	}
}
