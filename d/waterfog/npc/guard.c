// guard.c

inherit NPC;

void create()
{
	set_name("水烟阁武士", ({ "waterfog guard", "guard" }) );
	set("gender", "男性");
	set("age", 34);
	set("long", "这个人相貌十分魁梧。\n");

	set("attitude", "peaceful");
	set("combat_exp", 20000);
	set("score", 4000);

	set("str", 25);
	set("cor", 23);
	set("cps", 23);
	set("con", 27);

	set("force", 700);
	set("max_force", 700);
	set("force_factor", 5);

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :)
	}) );

	set_skill("force", 50);
	set_skill("unarmed", 60);
	set_skill("parry", 50);
	set_skill("dodge", 50);

	set_skill("celestial", 50);
	set_skill("celestrike", 50);

	map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");

	setup();

	carry_object(__DIR__"obj/guard_suit")->wear();
	carry_object(__DIR__"obj/leather_boot")->wear();
}
