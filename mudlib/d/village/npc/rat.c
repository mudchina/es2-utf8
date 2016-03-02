inherit NPC;

void create()
{
        set_name("大老鼠", ({ "rat" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一只鼠头鼠脑的大老鼠\n");

        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 80);

        setup();
}
