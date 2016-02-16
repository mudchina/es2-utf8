inherit NPC;

void create()
{
        set_name("信鸽", ({ "pigeon" }) );
        set("race", "野兽");
        set("age", 2);
        set("long", "一只乖巧的小信鸽\n");

        set("limbs", ({ "头部", "身体", "尾巴", "翅膀" }) );
        set("verbs", ({ "bite"}) );

        set_skill("dodge", 250);

        setup();
}
