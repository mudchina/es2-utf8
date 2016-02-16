// worker.c

inherit NPC;

void create()
{
        set_name("茶工", ({ "tea worker", "worker" }) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "茶工正在忙碌着。\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("unarmed", 10);
        set_skill("parry", 20);
	set_skill("dodge", 20);
	set_skill("throwing", 10);


        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
        }) );
        
        set("inquiry", ([
		"碧海银针" : "这要到香茗坊去问。", 
        ]) );

	setup();
	add_money("coin", 15);
        carry_object("/obj/cloth")->wear();
	carry_object("/u/cloud/obj/npc/worker/tea_leaf")->wield();
//        set("score",random(8)-4);
}

