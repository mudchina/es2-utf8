inherit NPC;

void create()
{
        set_name("蚂蚁", ({ "ant" }) );
        set("race", "野兽");
        set("age", 1);
        set("long", "一只小小的小蚂蚁\n");

        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 200);

        setup();
}
