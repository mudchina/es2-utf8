inherit NPC;

void create()
{
        set_name("商人", ({ "trader"}) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "这是一位从关外来的商人。\n");
        set("combat_exp", 80000);
        set("attitude", "friendly");
//        set("env/wimpy", 50);

        set_skill("celestial", 80);
        set_skill("celestrike", 80);
        set_skill("unarmed", 80);

        map_skill("force", "celestial");
        map_skill("unarmed", "celestrike");

        set("chat_chance", 30);
        set("chat_msg", ({
                "商人心有余悸地说道：我几乎死在绮云镇阿泰的手中！\n",
                (: random_move :),
        }) );
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "商人说道：杀人啦！你难道不怕官府缉拿吗？\n",
                (: random_move :),
        }) );


        setup();
        add_money("silver", 50);
        carry_object("/obj/cloth")->wear();
//        carry_object(__DIR__"obj/teablock");
//        carry_object(__DIR__"obj/perfume");
}

