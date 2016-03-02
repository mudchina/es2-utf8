// master chen

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("陈天星", ({ "master chen", "master" }) );
	set("title", "振远镖局总镖头");
        set("nickname", "刀拳双绝");
        set("rank_info/respect", "陈总镖头");
        set("gender", "男性" );
        set("age", 63);

        set("long",@LONG
陈天星从十五岁出道至今已经有近五十个年头了。二十五岁时自己
创建了振远镖局，苦心经营三十八载，使之而今成为京师第一大镖
局.而他凭着春风快意刀法和天邪神掌被江湖同道称为「刀掌双绝」
。绮云镇的陈剑秋是其侄子，如今也赫赫有名。
LONG);

        set("attitude", "peaceful");
        set("combat_exp", 1000000);
        set("score", 200000);

        set("str", 38);
        set("cor", 27);
        set("cps", 29);
        set("int", 30);

        set("max_force", 3200);
        set("force", 2000);
        set("force_factor", 40);

	set("inquiry", ([
		"name": "呵呵…你连我都不知道嘛？去打听打听吧。\n",
		"振远镖局": "这可是我一手创建的啊！可惜我也老了。\n",
		"陈剑秋": "他是我侄子，有什么事找他？\n",
		"天邪神掌": "那是我和於兰天武交换武功学的\n",
		"拜师": "是剑秋推荐的嘛？可有他的信物？\n"
		]));

        create_family("振远镖局", 0, "总镖头");
        assign_apprentice("弟子", 0);

        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("blade", 150);
        set_skill("parry", 100);
        set_skill("dodge", 80);

        set_skill("celestial", 80);
	set_skill("celestrike", 80);
	set_skill("spring-blade", 150);
	set_skill("pyrobat-steps", 70);

        map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");
	map_skill("blade", "spring-blade");
	map_skill("parry", "spring-blade");
	map_skill("dodge", "pyrobat-steps");

        setup();

	carry_object(__DIR__"obj/duoqing_blade")->wield();
}

int accept_object(object who, object ob)
{
	if ((string)ob->query("id") != "letter") {
		command("angry");
		tell_object(who, "不要戏弄我！\n");
		return 1;
		}

	if ((string)ob->query("master_id") != (string)who->query("id")) {
		message_vision("陈天星狐疑地望着$N，说
这是你的嘛？\n", who);
		return 1;
		}

        command("smile");
        command("say 果然是剑秋侄儿推荐来的。我收你啦。\n");
        command("recruit " + who->query("id") );
	
	return 1;
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
		ob->set("title", "振远镖局第一代弟子");
                ob->set("class", "guardman");
		}
}

