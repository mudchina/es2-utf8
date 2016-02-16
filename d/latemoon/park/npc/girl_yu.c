//girl_yu
inherit NPC;
 
void create()
{
        set_name("上官钰翎", ({ "yulin","yu-girl" }) );
        set("nickname", "玉涵湘");
        set("gender", "女性" );
        set("age", 20);
        set("long", @TEXT
TEXT
);
        set("combat_exp", 80000);
        set_skill("unarmed",20);
        set_skill("dodge", 90);
        set_skill("stormdance", 50);
        set_skill("force",100);
        set("force",4500);
         set("max_force", 500);
        set("force_factor",20);
        set("attitude","peaceful");
        setup();
        carry_object(__DIR__"obj/ring")->wear();
}
