inherit NPC;

void create()
{
        set_name("庾子建", ({ "yu shangshu","yu" }));
        set("title","兵部尚书");
        set("gender", "男性");
        set("age", 54);
        set("long",
                "他是当今皇上身边的红人，与宫中的关系也很熟络，手中掌管着\n"
		"兵马大权。不过能爬上这个位置，绝不是仅仅因为溜须拍马的缘\n"
		"故，当年战功赫赫，才有今天的地位。\n"
		);

        set("attitude", "peaceful");

        set("str", 27);
        set("int", 25);

        set("force", 1400);
        set("max_force", 800);
        set("force_factor", 10);
        set("max_gin", 200);
        set("eff_gin", 200);
        set("gin", 200);
        set("max_sen", 200);
        set("eff_sen", 200);
        set("sen", 200);

        set("combat_exp", 400000);

        set_skill("blade", 70);
        set_skill("shortsong-blade", 105);
        set_skill("force", 80);
        set_skill("wu-shun", 80);
        set_skill("parry", 50);
        set_skill("dodge", 60);
        set_skill("fall-steps", 60);

        map_skill("blade", "shortsong-blade");
        map_skill("parry", "shortsong-blade");
        map_skill("force", "wu-shun");
        map_skill("dodge", "fall-steps");

        setup();

        carry_object(__DIR__"obj/blade")->wield();
}

