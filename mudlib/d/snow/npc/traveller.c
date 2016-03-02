//traveller.c
inherit NPC;

void create()
{
        set_name("旅客", ({ "traveller"}));
        if(random(10)<7)
            set("gender", "男性" );
        else
            set("gender", "女性" );
        set("age", 15+random(50));
        set("long",
                "这是一位来雪亭镇的外地旅客.\n");
        set("chat_chance", 40);
        set("chat_msg", ({
(: random_move :)
 }));
        set("combat_exp", 600+random(400));
        set("attitude", "friendly");
        set_skill("dodge", 50);
        set_skill("unarmed", 40);
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin", 100);
        set("score",5-random(10));
}



