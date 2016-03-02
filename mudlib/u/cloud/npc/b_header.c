// b_header.c

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("陈剑秋", ({ "master guardman", "guardman", "master" }) );
        set("nickname", "霹雳刀");
        set("gender", "男性" );
        set("age", 38);
        set("str", 28);
        set("cor", 27);
        set("cps", 25);
        set("int", 23);

        set("max_force", 1000);
        set("force", 1000);
        set("force_factor", 3);

        set("rank_info/respect", "陈镖头");

        set("long",@LONG
    陈剑秋在十几年前创立了振远镖局，凭着一手春风快意刀法在远近
颇有些名头，因此镖局的生意还算可以。
LONG);

        create_family("振远镖局", 1, "镖头");

        set("combat_exp", 1000000);
        set("score", 20000);

//        set("chat_chance_combat", 60);
//        set("chat_msg_combat", ({
//                (: perform_action, "sword.counterattack" :)
//        }) );

        set_skill("unarmed", 60);
        set_skill("parry", 100);
        set_skill("dodge", 60);
        set_skill("blade", 100);
        set_skill("force", 20);
        set_skill("literate", 40);

        set_skill("spring-blade", 120);

        map_skill("blade", "spring-blade");

        set("inquiry", ([
                "淳风武馆" : 
"淳风武馆是先父所创，在下辱承其名，虽忝掌封山门户，不敢忘了先人遗志。",
                "name": "在下姓陈，人称霹雳刀",
                "霹雳刀": "江湖上的弟兄看得起在下就这么叫开了，实在是惭愧。",
		"陈天星": "他是我师叔，如果你帮我找到忘忧草并交给我，我就介绍你去那学艺。",
		"忘忧草": "我在乔阴县城游玩时丢的，据说被藏在一个隐蔽的地方了。",
			]) );

        setup();
        carry_object("/u/cloud/obj/npc/b_header/moon_blade")->wield();
}

void attempt_apprentice(object ob)
{
        if( ((int)ob->query_cor() < 25) ) {
// ("cor") < 25) ){ 
                command("say 走镖危险甚大，依我看" + 
RANK_D->query_respect(ob) + "似乎不宜冒这份险？");
                return;
        }
        command("smile");
        command("say 很好，" + RANK_D->query_respect(ob) + 
"多加努力，本镖局不会亏待你的。\n");
        command("recruit " + ob->query("id") );
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "guardman");
}

int accept_object(object who, object obj)
{
	object letter;

	if ((string) obj->query("name") != "忘忧草") {
		command ("angry");
		command ("say 你拿什么东西唬我？\n");
		return 1;
		}

	if ((string) who->query("family/family_name") != "振远镖局") {
		command ("heng");
		command ("say 你是何人？为什么有我的忘忧草？\n");
		return 1;
		}

	if ((string) obj->query("master_id") != (string) who->query("id") ) {
		message_vision ("$N笑了笑说：“这不是你得到的吧？”。\n", this_object());
		return 1;
		}

	message_vision ("$N大喜过望，：“好，好，我这就给你写信。”\n", this_object());
	message_vision ("$N提笔刷刷点点，顷刻间一封信写就。\n", this_object());
	message_vision ("陈剑秋交给$N一封信件。\n", who);
	letter = new  (__DIR__"obj/letter");
	letter->set("master_id", (string)who->query("id"));
	letter->move (who);
	message_vision ("$N说到路上小心，把信直接给陈师叔。\n", this_object());
	return 1;
}
 
