// heaven_soldier.c

#include <ansi.h>

inherit NPC;

void create()
{
	string *order = ({"甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸"});

	set_name("天" + (order[random(10)]) + "神兵", ({ "heaven soldier", "soldier" }) );
	set("long", "这是一位来自天界的守护神，专门担任护法之责。\n");
	set("attitude", "friendly");

	set("max_gin", 1000);
	set("max_kee", 1000);
	set("max_sen", 1000);

	set("max_atman", 100);
	set("atman", 100);
	set("max_mana", 100);
	set("mana", 100);

	set("str", 40);
	set("cor", 30);
	set("cps", 25);

	set("combat_exp", 100000);
/*
	set("chat_chance", 15);
	set("chat_msg_combat", ({
		name() + "喝道：孽障！竟敢对？\n"
	}) );
*/
	set_skill("sword", 70);
	set_skill("parry", 70);
	set_skill("dodge", 70);

	setup();

	carry_object(__DIR__"obj/golden_armor")->wear();
	carry_object(__DIR__"obj/golden_sword")->wield();
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	message("vision",
		HIY + name() + "说道：末将奉法主召唤，现在已经完成护法任务，就此告辞！\n\n"
		+ name() + "化成一道金光，冲上天际消失不见了。\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

void invocation(object who)
{
	int i;
	object *enemy;

	set("possessed", who); 
	message("vision",
		HIY "一道金光由天而降，金光中走出一个身穿金色战袍的将官。\n\n"
		+ name() + "说道：末将奉法主召唤，特来护法！\n" NOR,
		environment(), this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
		}
	}
	set_leader(who);
}
