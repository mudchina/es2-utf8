// dragon.c

inherit NPC;

void create()
{
	set_name("五爪金龙", ({ "dragon" }) );
	set("long",
		"这是一只生长在璃山的五爪金龙，它身上的鳞片闪闪发著耀眼的光芒。\n");

	set("race", "野兽");
	set("age", 600);
	set("attitude", "friendly");

	set("max_gin", 4000);
	set("max_kee", 6000);
	set("max_sen", 3000);

	set("str", 170);
	set("cor", 150);
	set("cps", 100);
	set("spi", 70);
	set("int", 40);

	set("limbs", ({ "头部", "身体", "前爪", "後爪", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set_temp("apply/attack", 100);
	set_temp("apply/dodge", 100);
	set_temp("apply/armor", 60);

	set("combat_exp", 1000000);
	setup();
}
