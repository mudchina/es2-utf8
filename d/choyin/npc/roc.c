// roc.c

inherit NPC;

void create()
{
	set_name("北冥大鹏", ({ "roc" }) );
	set("long",
		"这是一种来自北冥大泽的大鸟，它挥动翅膀卷起的飓风可以把人吹跑。\n");

	set("race", "野兽");
	set("age", 200);

	set("max_gin", 500);
	set("max_kee", 2000);
	set("max_sen", 1100);

	set("str", 80);
	set("cor", 40);
	set("spi", 40);
	set("int", 20);

	set("limbs", ({ "头部", "身体", "翅膀", "尾巴" }) );
	set("verbs", ({ "bite", "claw", "poke" }) );

	set_temp("apply/attack", 80);
	set_temp("apply/damage", 40);
	set_temp("apply/dodge", 70);
	set_temp("apply/armor", 30);

	set("combat_exp", 70000);
	setup();
}
