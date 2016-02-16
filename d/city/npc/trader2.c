inherit NPC;

void create()
{
        set_name("商人", ({ "trader"}) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "这是一位从关外来的商人。\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set_skill("unarmed", 30);
        set_skill("iron-cloth", 50);
        set_skill("bloodystrike", 70);
        map_skill("unarmed", "bloodystrike");
        set("chat_chance", 30);
        set("chat_msg", ({
                "什么世道，几个臭钱就可以买官作。\n",
		"这年头，生意不好做啊！\n",
		(: random_move :),
        }) );
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "光天化日，朗朗乾坤，你也想打劫？\n",
		(: random_move :),
        }) );


        setup();
        add_money("silver", 50);
        carry_object("/obj/cloth")->wear();
}

