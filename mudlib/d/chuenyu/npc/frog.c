
inherit NPC;

void create()
{
        set_name("蛐蛐", ({ "insect" }) );
        set("race", "野兽");
        set("age", 1);
        set("long", "一只方头方脑的大蛐蛐\n");

        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 150);

        setup();
}

