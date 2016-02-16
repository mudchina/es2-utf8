inherit NPC;

void create()
{
     set_name("清虚", ({"ching-shiu", "ching", "shiu"}) );
     set("gender", "男性");
     set("age", 36);
     set("class", "taoist");
     set("title", "茅山派第六代弟子");
     set("long", "一位神色和平的中年道士, 他正在教授他的徒弟如何运功\导气\n");
     set("attitude", "peaceful");
     set("combat_exp", 10000);

     set("spi", 28);
     set("cor", 22);

     set("force", 400);
     set("max_force", 400);
     set("force_factor", 5);
     set("mana", 500);
     set("max_mana", 500);
     set("atman", 300);
     set("max_atman", 300);
     
     set_skill("unarmed", 30);
     set_skill("dodge", 30);
     set_skill("force", 30);
     set_skill("gouyee", 40);
     set_skill("parry", 25);
     set_skill("spells", 35);
     set_skill("necromancy", 30);
     set_skill("magic", 35);
     set_skill("taoism", 40);

     map_skill("magic", "taoism");
     map_skill("spells", "necromancy");
     map_skill("force", "gouyee");

     setup();

     carry_object(__DIR__"obj/robe")->wear();
     carry_object(__DIR__"obj/hat")->wear();
     carry_object(__DIR__"obj/boots")->wear();
}
