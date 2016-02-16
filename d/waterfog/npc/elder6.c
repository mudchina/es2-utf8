// elder6.c

inherit NPC;

void create()
{
	set_name("陈坚石", ({ "chen jenxi", "chen", "jenxi" }) );
	set("title", "水烟阁六长老");
	set("gender", "男性");
	set("age", 57);
	set("long",
		"陈长老本来的名字已经没有人知道了，但是他的横练功\夫「石猿功\」成名\n"
		"数十年，加上个性有点....那个....顽固，因此水烟阁执法使潘军禅给他\n"
		"起了个绰号叫「坚石」，久而久之陈长老倒也挺喜欢这个名字，索性舍弃\n"
		"了原来的名字改名叫陈坚石。\n");

	set("attitude", "peaceful");
	set("combat_exp", 360000);
	set("score", 75000);

	set("str", 25);
	set("cor", 23);
	set("cps", 23);
	set("con", 27);

	set("force", 1700);
	set("max_force", 1700);
	set("force_factor", 5);

	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );

	set_temp("apply/armor", 100);

	set_skill("force", 100);
	set_skill("unarmed", 95);
	set_skill("staff", 100);
	set_skill("parry", 80);
	set_skill("dodge", 95);

	set_skill("celestial", 90);
	set_skill("celestrike", 80);

	map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");

	setup();

	carry_object("/d/waterfog/obj/iron_staff")->wield();
}
