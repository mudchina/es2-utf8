// wolf_dog.c

inherit NPC;

void create()
{
        set_name("狼狗", ({ "wolf dog", "dog" }) );
        set("race", "野兽");
        set("age", 4);
        set("long", "一只凶猛的狼狗，一只独眼正恶狠狠地瞪著你。\n");
	set("attitude", "aggressive");

	set("kee",200);
	set("eff_kee",200);
        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 10000);

        set("chat_chance", 15);
        set("chat_msg", ({
        	"狼狗用一只独眼恶狠狠地瞪著你。\n"
        }) );

        set("chat_msg_combat", ({
                "狼狗大声吠叫：汪！汪！汪！\n",
                "狼狗突然跳了起来，口中乱咬，向你扑来。\n"
        }) );

        set_temp("apply/attack", 45);
        set_temp("apply/damage", 40);
        set_temp("apply/armor", 45);

        setup();
}

