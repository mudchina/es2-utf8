inherit NPC;
 
void create()
{
        set_name("袭人", ({ "Shi Ren", "shi ren","shi" }) );
        set("gender", "女性" );
        set("age",28);
        set("long", @TEXT
TEXT
);
       set("class", "dancer");
       set("combat_exp", 7000);
        set_skill("unarmed", 40);
        set_skill("tenderzhi", 10);
        set_skill("dodge", 40);
        set_skill("force", 40);
        map_skill("unarmed","tenderzhi");
        set("force", 400);
        set("max_force", 400);
        set("force_factor", 2);

        create_family("晚月庄",4,"弟子");
        setup();
        carry_object("/d/latemoon/obj/skirt4")->wear();
        carry_object(__DIR__"obj/amulet")->wear();
}

