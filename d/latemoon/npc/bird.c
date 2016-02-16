inherit NPC;

void create()
{
    set_name("金丝雀", ({ "sparrow" }) );
	set("race", "野兽");
	set("age", 1);
	set("gender", "雌性");
	set("long", "一只翩翩起舞的小蝴蝶哦! \n");

    set("str", 20);

    set("combat_exp", 1000);
	set("attitude","peaceful");

	set("limbs", ({ "头部", "身体","翅膀" }) );
    set("verbs", ({ "bite","claw" }) );
	set_temp("apply/dodge", 100);

    set("chat_chance", 7);
	set("chat_msg", ({
		(: random_move :),
        "小金丝雀叽叽的叫! \n",
        "金丝雀用嘴整理羽毛。 \n"
	}) );

	setup();
}
