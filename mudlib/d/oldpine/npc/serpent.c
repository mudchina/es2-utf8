// serpent.c

inherit NPC;

void create()
{
	set_name("黑冠巨蟒", ({ "serpent" }) );
	set("long", "一只乌黑油亮的巨蟒，头上生著一个大肉瘤。\n");

	set("race", "野兽");
	set("age", 400);
	set("attitude", "aggressive");

	set("max_gin", 900);
	set("max_kee", 1800);
	set("max_sen", 500);

	set("str", 40);
	set("cor", 70);
	set("spi", 20);
	set("int", 10);

	set("limbs", ({ "头部", "躯干", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 60);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 90);
	set_temp("apply/dodge", 80);

	set("combat_exp",250000);
	set("score", 1000);
	setup();
}
