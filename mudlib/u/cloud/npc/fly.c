// fly.c

inherit NPC;

void create()
{
        set_name("苍蝇", ({ "fly" }) );
        set("race", "野兽");
        set("age", 1);
        set("long", "一只绿头金翅的大苍蝇。\n");

        set("limbs", ({ "头部", "身体", "翅膀" }) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 100);

        setup();
}

