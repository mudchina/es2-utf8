inherit NPC;

void create()
{
	set_name("蜘蛛", ({ "spider" }) );
	set("race", "野兽");
	set("age", 1);
	set("long",@LONG
这是一只体型相当大的蜘蛛, 看来有点吓人.

LONG
	);
	set("str", 20);

	set("limbs", ({ "头部", "身体" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 15);
	set_temp("apply/armor",5);
	set_temp("apply/dodge",10);

	setup();
}
