inherit NPC;

void create()
{
        set_name("蝴蝶", ({ "butterfly" }) );
        set("race", "野兽");
        set("age", 1);
        set("long", "一只美丽的小蝴蝶\n");

        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 250);

        setup();
}

