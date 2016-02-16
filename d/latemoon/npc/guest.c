//girl_yu
inherit NPC;
 
void create()
{
        set_name("芙云", ({ "fuyun" }) );
        set("gender", "女性" );
        set("age",17);
        set("long", @TEXT
TEXT
);
        set("combat_exp", 50000);
        set_skill("unarmed",20);
        set_skill("force",100);
//
        set_skill("force",100);
        set("force",4500);
        set("max_force",4500);
        set("force_factor",20);
        set("attitude","peaceful");
        setup();
}
