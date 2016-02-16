inherit NPC;

void create()
{
        set_name("庾清尘", ({ "qing_chen" }) );
        set("age", 20);
	set("gender", "女性");
	set("title", "尚书府小姐");
        set("long",
                "她是尚书府的千金。平时一直呆在自己的绣房里，所以虽然外界\n"
		"如何盛传她是如何如何的文雅、娴淑，却极少有能见过她的人。\n"
		"不知从何时起，她竺信起道教来，所以一切讲究素雅。\n"
                );

        set("attitude", "peaceful");

        set("per", 27);
	set("int", 30);

        set("force", 500);
        set("max_force", 300);
        set("force_factor", 20);

        set("atman", 1000);
        set("max_atman", 1000);

        set("mana", 2000);
        set("max_mana", 1000);
        set("mana_factor", 3);

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
        }) );

        set("combat_exp", 70000);

        set_skill("literate", 90);
        set_skill("magic", 30);
        set_skill("force", 50);
        set_skill("spells", 70);
        set_skill("scratching", 60);
        set_skill("sword", 40);
        set_skill("parry", 40);
        set_skill("dodge", 60);
	set_skill("stormdance", 60);
        set_skill("gouyee", 60);
        set_skill("necromancy", 60);

        map_skill("spells", "necromancy");
	map_skill("sword", "scratching");
	map_skill("parry", "scratching");
	map_skill("force", "gouyee");
	map_skill("dodge", "stormdance");

        setup();
        carry_object(__DIR__"obj/white_cloth")->wear();
	carry_object(__DIR__"obj/sword")->wield();
}


