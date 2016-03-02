// scholar.c

inherit NPC;

void create()
{
	set_name("书生", ({ "scholar" }) );
	set("long", "一个看起来相当斯文的书生，正拿著一本书摇头晃脑地读著。\n");
	set("age", 23);
	set("attitude", "peaceful");
	set("combat_exp", 10);
	set("env/wimpy", 100);
	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}) );
	setup();
	carry_object(__DIR__"obj/book");
	carry_object("/obj/cloth")->wear();
}

