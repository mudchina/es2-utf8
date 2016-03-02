inherit NPC;
inherit F_MASTER ; 

void create()
{
        set_name("瑷伦",  ({ "eelon"  }) );
        set("gender", "女性" );
         set("age", 37);
        set("long", @TEXT
TEXT
);
        set("attitude", "peaceful");
        set("class", "dancer");
	set("title","晚月庄开山祖师");
        set("combat_exp", 3000000);
        set("score", 1000);

	set("str",21);
	set("int",28);
	
        set_skill("unarmed",150);
        set_skill("dodge", 150);
	set_skill("sword",120);
	set_skill("force",150);
	set_skill("parry",120);
	set_skill("whip",150);
	set_skill("iceforce",130);
	set_skill("throwing",150);	
        set_skill("stormdance", 130);
        set_skill("tenderzhi", 130);
	set_skill("snowwhip",130);
        map_skill("dodge","stormdance");
        map_skill("unarmed","tenderzhi");
	map_skill("force","iceforce");
	map_skill("whip","snowwhip");
        set("force", 4000);
        set("max_force", 3000);
        set("force_factor", 5);
	
	set("inquiry", ([
                "拜师":
		"哦....想拜老身为师，好...\n不过得先接受测试(accept test)，接下我三鞭。"
        ]) );

        create_family("晚月庄", 0, "弟子");

        setup();
        carry_object("/d/latemoon/obj/deer_boot")->wear();
        carry_object("/d/latemoon/obj/blue_dress")->wear();
	carry_object("/obj/weapon/whip")->wield();
}

void init()
{
	::init();
	add_action("do_accept","accept");
}

int do_accept(string arg)
{
        mapping guild;

        if( arg== "test" ) {
		if ( this_player()->query("gender") != "女性" ) {
			command("say 老身不收男徒!\n");
			return(1);
		}
		if ( this_player()->query("combat_exp") < 100000 )
			return 1 ;			
		say("\n瑷伦说道：小心了，这是第一鞭...\n\n");

                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0
                || !present(this_player(), environment())) {

			command("sigh");
			command("shake");
                        return 1;
                }
		say("\n瑷伦面露微笑：好！第二鞭来了...\n\n");

                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0
                || !present(this_player(), environment())) {

			say("\n瑷伦叹了口气道：看来还是不行啊...\n\n");
                        return 1;
                }
		say("\n瑷伦鼓励道：很不错，看这最后一鞭...\n\n");

                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0
                || !present(this_player(), environment())) {
			say("\n瑷伦叹了口气道：太可惜了！\n\n");
			command("shake");
                        return 1;
                }
		say("\n瑷伦露出慈祥的面容：看来我没看错人。\n\n");

                command("recruit " + this_player()->query("id") );
		this_player()->set("title","晚月庄第一代弟子");
                return 1;
        }
        return 0;
}

void attempt_apprentice(object me)
{
	if ( me->query("combat_exp") < 100000 ) {
     command("say 拜师! 不敢当，我都老了!你去找「芷萍」好了，看她收不收你? ");
	}
	else
	if ( me->query("gender") != "女性" )
	command("say 老身不收男徒!\n");
	else
        if((string)me->query("title")!="普通百姓")
         {
            command("chat "+me->query("title")+me->query("nickname")+
            me->query("name")+"要叛师！！！");
            command("angry");
            kill_ob(me);
            return;
         }

	else {
        say(RANK_D->query_respect(me) + "若真的有心，不妨让我看看你的所学\n");

        tell_object(me, "如果想拜师的话，就请接受测试（accept test）\n");
}
}
