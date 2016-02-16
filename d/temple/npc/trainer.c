// tao_first.cst.c

inherit NPC;

void create()
{
        set_name("僵尸侍者", ({ "trainer" }) );
        set("nickname", "僵尸侍者");
        set("gender", "男性");
        set("age", 27);
        set("long",

"僵尸侍者是林忌的弟子，着一身黑色的道袍\n"
);
        set("combat_exp", 14000);
        set("score", 200);

        set("class", "taoist");

        set("str", 20);
        set("int", 30);
        set("cor", 20);
        set("cps", 30);
        set("spi", 30);

        set("force", 500);
        set("max_force", 500);
        set("force_factor", 20);

        set("atman", 300);
        set("max_atman", 300);

        set("mana", 400);
        set("max_mana", 400);
        set("mana_factor", 20);

        set("inquiry", ([
                "谷衣心法":
"谷衣心法是我茅山派为对抗邪魔外道所创的内功心法。\n",
                "茅山派":
"我茅山派自张天师开山立派至今，世世代代皆以降妖伏魔为己任。\n"
        ]) );
        set("chat_chance", 25);
        set("chat_msg", ({
                "僵尸侍者说道：我们茅山派实力最强！谁敢欺负我们？\n",
                "僵尸侍者说道：大家快加入茅山派吧! \n",
                (:random_move :)
        }) );

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
                (: command("cast manimate on corpse") :),
                (: command("cast animate on corpse") :),
        }) );

        create_family("茅山派", 6, "弟子");

        set_skill("literate", 10);
        set_skill("magic", 60);
        set_skill("force", 50);
        set_skill("spells", 60);
        set_skill("scratching", 20);
        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("gouyee", 60);

        set_skill("taoism", 60);
        set_skill("necromancy", 60);

        map_skill("spells", "necromancy");

        set_temp("apply/dodge", 40);
        set_temp("apply/armor", 40);

        setup();

        carry_object("/obj/weapon/longsword")->wield();
        carry_object(__DIR__"obj/magic_book");
        carry_object(__DIR__"obj/spells_book");
        set("score",-10);
}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="茅山派" ) {
                command("nod");
                command("say 进招吧。");
                return 1;
        }
        command("say 茅山派不和别派的人过招。");
        return 0;
}
