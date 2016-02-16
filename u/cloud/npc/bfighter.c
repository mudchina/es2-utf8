// bfighter.c

inherit NPC;

void create()
{
        set_name("趟子手", ({ "bfighter" }) );
        set("gender", "男性" );
        set("age", 38);
        set("str", 28);
        set("cor", 27);
        set("cps", 25);
        set("int", 23);

        set("max_force", 100);
        set("force", 100);
        set("force_factor", 3);

        set("pursuer", 1);
        set("env/wimpy", 30);

        set("long",@LONG
这是一位镖局的趟子手，负责镖局的护镖任务。
LONG);

        create_family("振远镖局", 2, "趟子手");

        set("combat_exp", 10000);
        set("score", 200);

        set("chat_chance", 20);
        set("chat_msg", ({
                "趟子手喊道：振远镖局..., 盛名远扬...\n",
                (:random_move :)
        }) );

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                "趟子手喊道：教你尝尝我的厉害！\n",
                "趟子手叫道：我们镖局可不是好惹的！\n"
                "趟子手大叫：我一定要杀了你，替镖局扬名！\n"
        }) );

        set_skill("unarmed", 60);
        set_skill("parry", 50);
        set_skill("dodge", 30);
        set_skill("blade", 50);
        set_skill("force", 20);
        set_skill("literate", 10);

        set_skill("spring-blade", 40);

        map_skill("blade", "spring-blade");

        setup();
        carry_object("/obj/weapon/blade")->wield();
}
