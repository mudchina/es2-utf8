// huge_worm.c

inherit NPC;

void create()
{
	set_name("巨岩蛭", ({ "huge rock leech", "leech" }) );
	set("long",
		"一条色作浅灰，带著白色斑点的水蛭模样怪虫，口中露出六对白森森\n"
		"的牙齿，看起来恶心极了。\n");

	set("race", "野兽");
	set("unit", "条");
	set("age", 8);

	set("max_gin", 400);
	set("max_kee", 900);
	set("max_sen", 400);

	set("str", 80);
	set("con", 40);
	set("cor", 80);
	set("cps", 5);
	set("spi", 1);
	set("int", 1);
	set("kar", 5);
	set("per", 0);

	set("limbs", ({ "头部", "躯干" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 60);
	set_temp("apply/damage", 35);
	set_temp("apply/dodge", 30);
	set_temp("apply/armor", 80);

	set("combat_exp", 10000);
	setup();
}
