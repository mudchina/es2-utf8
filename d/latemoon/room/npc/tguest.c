//girl_yu
inherit NPC;
 
void create()
{
        set_name("梦玉楼", ({ "yu lou", "yulou","lou" }) );
        set("gender", "女性" );
        set("age",17);
        set("long", @TEXT
TEXT
);
        set("combat_exp", 70000);
        set_skill("unarmed", 50);
        set_skill("dodge", 70);
        set_skill("sword",70);
        set_skill("snowshade-sword", 30);
        set_skill("stormdance", 10);
        set_skill("force",100);
        map_skill("sword","snowshade-sword");
        set("force", 2000);
        set("max_force", 1000);
        set("force_factor", 15);
        set("attitude","peaceful");
        create_family("天山派",11,"弟子");
        setup();
         carry_object(__DIR__"obj/token")->wear();
        carry_object(__DIR__"obj/longsword")->wield();
}
