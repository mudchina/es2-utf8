// venomsnake.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("金银花蛇", ({ "venomsnake", "snake" }) );
	set("long",	"一支昂首吐信的毒蛇正虎视眈眈地盯著你。\n");

	set("race", "野兽");
	set("age", 5);
	set("pursuer", 1);
        set("attitude", "aggressive");

	set("max_gin", 260);
	set("max_kee", 260);
	set("max_sen", 100);

	set("str", 10);
	set("cor", 50);

	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 70);
	set_temp("apply/damage", 70);
	set_temp("apply/armor", 60);

	set("combat_exp", 30000);
	setup();
}

int hit_ob(object me, object ob, int damage)
{
	if( random(damage) > (int)ob->query_temp("apply/armor")
	&&	(int)ob->query_condition("snake_poison") < 10 ) {
		ob->apply_condition("snake_poison", 20);
		tell_object(ob, HIG "你觉得被咬中的地方一阵麻痒！\n" NOR );
	}
}
