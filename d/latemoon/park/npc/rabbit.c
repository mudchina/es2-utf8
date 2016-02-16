inherit NPC;

void create()
{
     set_name("小白兔", ({ "rabbit" }) );
	set("race", "野兽");
	set("age", 1);
	set("gender", "雌性");
     set("long", "一只红眼睛的小白兔。\n");

    set("str", 20);

    set("combat_exp", 1000);
	set("attitude","peaceful");

     set("limbs", ({ "头部", "身体","前脚","后腿" }) );
    set("verbs", ({ "bite","claw" }) );
    set_temp("apply/dodge", 30);

    set("chat_chance", 7);
	set("chat_msg", ({
		(: random_move :),
        "小白兔蹦蹦跳跳的。\n",
        "小白兔用嘴舔前肢。 \n"
	}) );

	setup();
}
