// crazy_dog.c

inherit NPC;

void create()
{
	set_name("疯狗", ({ "crazy dog", "dog" }) );
	set("race", "野兽");
	set("age", 4);
	set("long", "一只浑身脏兮兮的野狗，一双眼睛正恶狠狠地瞪著你。\n");
	set("attitude", "aggressive");
	
	set("str", 26);
	set("cor", 30);

	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 100);

	set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :),
	}) );
	
	set("chat_msg_combat", ({
		(: random_move :),
		"疯狗大声吠叫：汪！汪！汪！汪！汪！汪！\n",
		"疯狗突然跳了起来，口中乱咬，却不知道是在咬谁。\n"
	}) );
		
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);

	setup();
//	replace_program(NPC);
}
