// bandit_hwang.c

inherit NPC;

void create()
{
	set_name("黄霸", ({ "hwang", "bandit" }) );
	set("title", "野羊山土匪头目");
	set("nickname", "日月槌");
	set("gender", "男性");
	set("age", 31);
	set("long",
		"黄霸原是关外一个山寨的寨主，后来因为逃避官府追捕而到也羊山\n"
		"避祸，他的成名武器是一对各重四十斤的大金槌，内功\跟横练功\夫\n"
		"也都有不错的造诣。\n");
	set("combat_exp", 150000);
	set("attitude", "friendly");
	set("pursuer", 1);

	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 30);

	set("str", 30);
	set("con", 30);
	set("cps", 25);
	set("cor", 26);
	set("spi", 16);
	set("int", 21);
	set("kar", 19);
	set("per", 13);

	set_skill("hammer", 90);
	set_skill("parry", 80);
	set_skill("dodge", 90);
	set_skill("force", 60);
	set_skill("serpentforce", 70);
	map_skill("force", "serpentforce");

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 90);
	set_temp("apply/armor", 100);

	setup();
	carry_object(__DIR__"obj/sledge_hammer")->wield();
	carry_object(__DIR__"obj/sledge_hammer")->wield();
	carry_object(__DIR__"obj/boots")->wear();
	carry_object("/obj/cloth")->wear();
	add_money("silver", 40);
}
