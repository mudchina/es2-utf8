// lady.c

inherit NPC;

void create()
{
	set_name("妇人", ({ "lady" }) );
	set("long", "一个衣饰华丽的妇人正跪在这里虔诚地膜拜著。\n");
	set("age", 32);
	set("gender", "女性");
	set("attitude", "peaceful");
	set("combat_exp", 10);
	set("env/wimpy", 100);
	setup();
	carry_object(__DIR__"obj/lady_dress")->wear();
	carry_object(__DIR__"obj/silver_clasp")->wear();
	add_money("silver", 10);
}

