// tall_bandit.c

inherit NPC;

void create()
{
	set_name("土匪", ({ "bandit" }) );
	set("gender", "男性");
	set("age", 27);
	set("long",	"这家伙长得高高瘦瘦，脸色苍白，一付无精打采的样子。\n");
	set("combat_exp", 900);
	set("score", 100);
	set("attitude", "aggressive");
	set_skill("sword", 15);
	set_skill("parry", 15);
	set_skill("dodge", 10);
	setup();
	carry_object(__DIR__"obj/long_sword")->wield();
	add_money("silver", 6);
}
