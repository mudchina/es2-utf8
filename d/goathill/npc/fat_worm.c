// fat_worm.c

inherit NPC;

void create()
{
	set_name("肥岩蛭", ({ "fat rock leech", "leech" }) );
	set("long",
		"一条色作浅灰，带著白色斑点的水蛭模样怪虫，口中露出六对白森森\n"
		"的牙齿，看起来恶心极了。\n");

	set("race", "野兽");
	set("unit", "条");
	set("age", 5);

	set("max_gin", 400);
	set("max_kee", 400);
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

	set_temp("apply/attack", 40);
	set_temp("apply/damage", 30);
	set_temp("apply/dodge", 20);
	set_temp("apply/armor", 40);

	set("combat_exp", 3000);
	set("corpse_ob", __DIR__"obj/dead_leech");
	setup();
}
