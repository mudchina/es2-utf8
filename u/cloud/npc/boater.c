// boater.c

inherit NPC;

string	cross_river();

void create()
{
        set_name("船夫", ({ "boater" }) );
        set("title", "渡口");
        set("gender", "男性" );
        set("age", 30);
        set("long", "船夫的皮肤晒得黝黑，脸上的沧桑是多年摆渡的痕迹。\n");
	set("str", 27);
        set("combat_exp", 1500);
        set("attitude", "heroism");
        set_skill("unarmed", 100);
        set_skill("parry", 50);
        set_skill("dodge", 30);

        set("inquiry", ([
		"过江" : (: cross_river :),
		"摆渡" : (: cross_river :), 
        ]) );

	setup();
	add_money("coin", 200);
        carry_object("/obj/cloth")->wear();
}

int accept_object(object who, object ob)
{
        if( !who->query("marks/船夫") ) {
                if( ob->value() >= 2 ) {
			command("nod");
			message("vision", "船夫说：客官可以过江啦！\n",
                                 who );
	                message("vision", "船夫拉过条小船，你走了上去。\n",
                        	 who );
                        who->set("marks/船夫", 1);
                        return 1;
                } else {
                        say("这么少？我还要养家呀！\n");
                        return 0;
                }
        } else{
                say("多谢这位"+RANK_D->query_respect(ob)+"！\n");
		who->set("marks/船夫", 0);
	}
        return 1;
}

string	cross_river()
{
	return "交五两银子";
}

