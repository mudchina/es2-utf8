// shiao.c

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("骆云舟", ({ "master scholar", "master" }) );

        set("gender", "男性");
        set("age", 35);
        set("long",
		"骆云舟生於京城有名的武林世家，他的本名是骆建炎，但是因为生性喜爱\n"
		"四处游荡，遂自号「云舟」，四处游山玩水，结交豪杰异人。数年前继承\n"
		"其父骆易而成为步玄派的新任掌门，但是喜爱飘泊的个性仍然不改，令门\n"
		"中耆宿头痛不已。\n" );

	set("attitude", "peaceful");
	create_family("步玄派", 7, "掌门人");

	set("str", 26);
	set("cor", 30);
	set("int", 28);
	set("cps", 30);

	set("force", 3000);
	set("max_force", 1600);
	set("force_factor", 20);

	set("combat_exp", 1000000);
	set("score", 200000);

	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: perform_action, "move.hasten" :),
        }) );
	
	set_skill("dodge", 100);
	set_skill("force", 80);
	set_skill("instruments", 70);
	set_skill("literate", 150);
	set_skill("move", 100);
	set_skill("music", 100);
	set_skill("parry", 90);
	set_skill("perception", 80);
	set_skill("sword", 100);
	set_skill("unarmed", 60);
	set_skill("mysterrier",120);
	set_skill("mystforce", 100);
	set_skill("mystsword", 100);
	map_skill("move", "mysterrier");
	map_skill("dodge", "mysterrier");
	map_skill("force", "mystforce");
	map_skill("sword", "mystsword");
	map_skill("parry", "mystsword");

	setup();
        carry_object(__DIR__"windspring")->wield();
        carry_object("/obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
         if (ob->query("marks/桃林"))  {
		 command("smile");
        	command("say 很好，" + RANK_D->query_respect(ob) +
"多加努力，他日必定有成。\n");
        	command("recruit " + ob->query("id") );
		ob->set("marks/书生", 0); 
		ob->set("marks/桃林", 0);	
		}
	    else {
		command ("say 你还是先走一趟东边的桃林吧。\n");
		ob->set("marks/书生", 1);
		} 
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "scholar");
}

