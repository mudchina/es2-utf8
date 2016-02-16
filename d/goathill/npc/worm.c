// worm.c

inherit NPC;

void create()
{
	set_name("岩蛭", ({ "rock leech", "leech" }) );
	set("long",
		"一条色作浅灰，带著白色斑点的水蛭模样怪虫，口中露出六对白森森\n"
		"的牙齿，看起来恶心极了。\n");

	set("race", "野兽");
	set("unit", "条");
	set("age", 5);

	set("max_gin", 200);
	set("max_kee", 200);
	set("max_sen", 200);

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

	set_temp("apply/attack", 30);
	set_temp("apply/damage", 20);
	set_temp("apply/dodge", 20);
	set_temp("apply/armor", 30);

	set("combat_exp", 1000);
	set("corpse_ob", __DIR__"obj/dead_leech");
	setup();
}
