// little_tiger.c

inherit NPC;

void create()
{
	set_name("小天邪虎", ({ "little tiger", "tiger" }) );
	set("long",
		"这是一只天邪派的灵兽「天邪虎」，火红的毛皮上有著如白银般的\n"
		"白纹，然而这只天邪虎的年纪显然还很小，说不定还不到两岁。\n");

	set("race", "野兽");
	set("age", 1);
	set("attitude", "friendly");

	set("max_gin", 300);
	set("max_kee", 300);
	set("max_sen", 100);

	set("str", 26);
	set("con", 36);
	set("cor", 20);
	set("spi", 30);
	set("int", 60);
	set("cps", 25);
	set("per", 60);
	set("kar", 70);

	set("limbs", ({ "头部", "身体", "前脚", "后腿", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set_temp("apply/attack", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 10);

	set("combat_exp", 2000);
	setup();
}
