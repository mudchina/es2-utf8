
inherit NPC;

void create()
{
     set_name("烧饭僧", ({"cook bonze", "bonze"}));
     set("gender", "男性");
     set("class", "bonze");
     set("age",35);
     set("long","一位长得肥肥胖胖, 福福泰泰的中年僧人。\n");
     set("combat_exp", 1100);
     set("attitude", "friendly");

     set("max_force", 800);
     set("force", 800);
     set("force_factor", 2);

     set_skill("force",40);
     set_skill("unarmed",40);
     set_skill("blade",45);
     set_skill("dodge",35);
     set_skill("buddhism",40);
     set_skill("lotusforce",50);

     map_skill("force", "lotusforce");

     setup();

     carry_object(__DIR__"obj/carver")->wield();
     carry_object(__DIR__"obj/cloth")->wear();
     carry_object(__DIR__"obj/shoe")->wear();
}

int accept_fight(object me)
{
     command("say 阿弥陀佛 !! 贫僧的菜刀是用来切菜的, 不是用来砍人的。\n");
     return 0;
}
