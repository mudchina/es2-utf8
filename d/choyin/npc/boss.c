// boss.c

inherit NPC;

void create()
{
	set_name("汤掌柜", ({ "boss tang", "tang", "boss" }) );
	set("long",
		"汤掌柜是这家大酒楼的主人，别看他只是一个小小的酒楼老板，乔阴\n"
		"县境内除了知县老爷以外，恐怕就属他最财大势大。\n" );
	set("age", 46);
	set("attitude", "peaceful");
	set("combat_exp", 1000);
	set("inquiry", ([
		"name": "在下姓汤单名一个业字。\n",
		"here": "此处便是福林酒楼，客倌如要点菜，吩咐店里的小二一声便可。\n",
		"汤业": "不敢，在下便是汤业，不知客倌有何吩咐？\n",
		"福林酒楼": "这里就是，客倌是第一次来吗？\n"
	]) );
	setup();
	add_money("silver", 15);
	carry_object("/obj/cloth")->wear();
}

