// dog.c

inherit NPC;

void create()
{
	set_name("野狗", ({ "dog" }) );
	set("race", "野兽");
	set("age", 3);
	set("long", "一只浑身脏兮兮的野狗。\n");
	
	set("str", 24);
	set("cor", 26);

	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
	
	set_temp("apply/attack", 10);
	set_temp("armor", 3);

	setup();
}
