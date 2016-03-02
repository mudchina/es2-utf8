inherit NPC;
 
void create()
{
         object ob;

        set_name("婢女", ({ "girl","servant" }) );
        set("gender", "女性" );
        set("age",30);
        set("long", @TEXT
TEXT
);
       set("class", "dancer");
       set("combat_exp", 10000);
        set_skill("unarmed", 40);
        set_skill("dodge", 50);
        set_skill("force",50);
        set("force", 50);
        set("max_force", 50);

        setup();
        ob = carry_object(__DIR__"obj/needle");
        ob->set_amount(30);
        carry_object("/d/latemoon/obj/skirt")->wear();
}

