// mother.c

inherit NPC;

void create()
{
	set_name("鸨母", ({ "mother" }) );
	set("gender", "女性" );
	set("age", 49);
	set("str", 10);
	set("per", 26);
	set("long", @LONG
    鸨母是个浓妆艳抹的中年女子，身材微胖，全身上下珠光宝气。
LONG
);
	set("combat_exp", 10);
	set("attitude", "friendly");

	set_skill("unarmed", 100);
	set_skill("parry", 50);

	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"鸨母说道：你当这里是什么地方，敢来这里骚扰？\n",
	}) );
	set("inquiry", ([
		"怡红院": "哎呀！就是我们这里啊，您里面请",
	]) );

	setup();
	
	carry_object("/u/cloud/obj/npc/lm_guard/color_cloth")->wear();
	carry_object("/obj/toy/poison_dust.c");
}

