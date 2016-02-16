inherit NPC;

void create()
{
     set_name("老道士", ({"old taoist", "taoist"}) );
     set("gender", "男性");
     set("age", 46);
     set("class", "taoist");
     set("long", "一位四处云游的老道士, 他正在观心观挂单中。\n"
                 "看他饱经沧桑的脸孔, 似乎他也是经历过无数的大风大浪。\n");
     set("attitude", "peaceful");
     set("combat_exp", 2500);

     set_skill("dodge", 10);
     set_skill("parry", 15);
     set_skill("whip", 25);

     setup();

     carry_object(__DIR__"obj/whip")->wield();
     carry_object(__DIR__"obj/old_robe")->wear();
     add_money("silver", 5);
}

int accept_fight(object ob)
{
     command("say 无量寿佛 ! 贫道年迈力衰, 怎是施主的对手。\n");
     return 0;
}
