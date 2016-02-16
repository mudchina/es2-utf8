// master.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("早川直义", ({ "master ronin", "ronin" }) );
	set("gender", "男性");
	set("age", 52);
	set("attitude", "peaceful");

	set("str", 26);
	set("int", 24);

	set("force", 1800);
	set("max_force", 1800);
	set("force_factor", 10);

	set("combat_exp", 1000000);
	set("score", 200000);
/*
	set("chat_chance", 30);
	set("chat_msg", ({
	}) );
*/
	create_family("鬼笠馆浪人", 11, "宗道");

/*
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: consider :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );
*/
	set_skill("unarmed", 30);
	set_skill("staff", 50);
	set_skill("sword", 100);
	set_skill("throwing", 60);
	set_skill("force", 60);
	set_skill("parry", 100);
	set_skill("dodge", 70);

/*
	set_skill("spicyclaw", 100);
	set_skill("serpentforce", 100);

	map_skill("unarmed", "spicyclaw");
	map_skill("force", "serpentforce");
*/
	setup();
}

/*
void attempt_apprentice(object me)
{
	command("look " + me->query("id"));
	if( me->can_afford(100) ) {
		command("say 我们花紫会只收化子，" + RANK_D->query_respect(me)
			+ "您还是回去享福吧。\n");
		return;
	} else {
		command("nod");
		command("recruit " + me->query("id"));
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "beggar");
}


*/