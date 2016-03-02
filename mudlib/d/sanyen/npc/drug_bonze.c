
inherit NPC;

void create()
{
     set_name("药僧", ({"drug bonze", "bonze"}));
     set("gender", "男性");
     set("class", "bonze");
     set("age",25);
     set("long","一位长得相当精壮的年轻僧人, 他正在整理药材。\n");
     set("combat_exp", 1800);
     set("attitude", "heroism");

     set("str", 30);
     set("int", 28);

     set("max_force", 1000);
     set("force", 1000);
     set("force_factor", 3);

     set_skill("force",50);
     set_skill("unarmed",55);
     set_skill("dodge",45);
     set_skill("buddhism",60);
     set_skill("lotusforce",58);

     map_skill("force", "lotusforce");

     setup();

     carry_object(__DIR__"obj/cloth")->wear();
     carry_object(__DIR__"obj/shoe")->wear();
}

