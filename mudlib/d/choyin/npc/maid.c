// maid.c

inherit NPC;

void create()
{
	set_name("丫鬟", ({ "maid" }) );
	set("long", "一个服侍有钱人家小姐的丫鬟，正无聊地玩弄著衣角。\n");
	set("age", 17);
	set("gender", "女性");
	set("attitude", "peaceful");
	set("combat_exp", 10);
	set("env/wimpy", 100);
	set("inquiry", ([
		"here": "这里啊？这里就是乔阴县有名的翠柳湖啊！",
	]) );
	setup();
	carry_object("/obj/cloth")->wear();
}

