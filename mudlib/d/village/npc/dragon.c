// dragon.c

inherit NPC;

void create()
{
	set_name("白鳞冰龙", ({ "icedragon","dragon" }) );
	set("long",
		"一只浑身长满白鳞的龙，\n");

	set("race", "野兽");
	set("age", 600);
	set("attitude", "aggressive");

	set("max_gin", 1300);
	set("max_kee", 5000);
	set("max_sen", 800);

	set("str", 40);
	set("cor", 200);
	set("cps", 30);
	set("spi", 70);
	set("int", 20);
        set("con",1000);
	set("limbs", ({ "头部", "身体", "前爪", "後爪", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set_temp("apply/attack", 50);
	set_temp("apply/dodge", 120);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 10);

	set("combat_exp", 1000000);
	setup();
}
