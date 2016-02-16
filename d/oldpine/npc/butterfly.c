inherit NPC;

void create()
{
	set_name("蝴蝶", ({ "butterfly" }) );
	set("race", "野兽");
	set("age", 1);
	set("gender", "雌性");
	set("long", "一只翩翩起舞的小蝴蝶哦! \n");

	set("str", 6);
	set("cor", 8);
	set("per", 33);

    set("combat_exp", 100);
	set("score", 10);
	set("attitude","peaceful");

	set("limbs", ({ "头部", "身体","翅膀" }) );
	set("verbs", ({ "bite" }) );
    set_temp("apply/dodge", 50);

   set("chat_chance", 15);
	set("chat_msg", ({
//		(: random_move :),
		"蝴蝶拍动著翅膀! \n",
		"蝴蝶停在花上吸花蜜。 \n"
	}) );

	setup();
}
