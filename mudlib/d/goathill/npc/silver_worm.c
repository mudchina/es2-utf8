// silver_worm.c

inherit NPC;

void create()
{
	set_name("银色岩蛭", ({ "silver rock leech", "leech" }) );
	set("long",
		"这条岩蛭看起来银光闪闪，跟其他丑恶的岩蛭大不相同，你注意到它\n"
		"口中白牙中竟微微地发著光，不知道肚子里藏了什么东西。\n");

	set("race", "野兽");
	set("unit", "条");
	set("age", 145);

	set("max_gin", 1500);
	set("max_kee", 1500);
	set("max_sen", 1500);

	set("str", 80);
	set("con", 80);
	set("cor", 80);
	set("cps", 80);
	set("spi", 20);
	set("int", 40);
	set("kar", 80);
	set("per", 10);

	set("limbs", ({ "头部", "躯干" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 90);
	set_temp("apply/damage", 55);
	set_temp("apply/dodge", 90);
	set_temp("apply/armor", 160);
	set_temp("apply/armor_vs_force", 1000);

	set("combat_exp", 400000);
	setup();
}
