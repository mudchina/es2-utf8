inherit NPC;

void create()
{
        set_name("仙鹤",({"crane"}) );
        set("long", "白羽如雪，不似凡间之物。 \n");
        set("race", "野兽");
        set("unit", "只");
        set("max_gin", 300);
        set("max_kee", 900);
        set("max_sen", 900);
        set("limbs", ({"翅"}));
        set("attitude", "peaceful");
        set("combat_exp", 1000000);
        set("env/wimpy",100);
        set_skill("parry", 10);
        set_skill("dodge", 150);
        set_skill("move", 150);
        setup();
}
 
