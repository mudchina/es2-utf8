inherit NPC;
 
void create()
{
        set_name("婢女", ({ "girl","servant" }) );
        set("gender", "女性" );
        set("age",18);
        set("long", @TEXT
TEXT
);
       set("class", "dancer");
       set("combat_exp", 100);
        set_skill("unarmed", 5);
        set_skill("dodge", 10);
        set_skill("force",50);
        set("force", 50);
        set("max_force", 50);

        setup();
        carry_object("/d/latemoon/obj/skirt")->wear();
}

