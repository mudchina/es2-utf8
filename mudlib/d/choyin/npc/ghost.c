// ghost.c

inherit NPC;

void create()
{
	set_name("孤魂野鬼", ({ "wandering ghost", "ghost" }) );
	set("age", 45);
	
	set("str", 24);
	set("cor", 26);

	set("env/wimpy", 70);
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);
	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :),
	}) );
	setup();
	carry_object(__DIR__"obj/cloth_piece");
}

int is_ghost() { return 1; }
