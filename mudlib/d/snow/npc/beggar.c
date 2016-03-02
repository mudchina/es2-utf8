// beggar.c

inherit NPC;

void create()
{
	set_name("乞丐", ({ "beggar" }) );
	set("gender", "男性" );
	set("age", 53);
	set("long", "一个满脸风霜之色的老乞丐。\n");
	set("combat_exp", 100);
	set("str", 27);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 2);
	setup();
	set("chat_chance", 15);
	set("chat_msg", ({
		"乞丐说道：好心的大爷哪～ 赏我要饭的几文钱吧～\n",
		"乞丐懒洋洋地打了个哈欠。\n",
		"乞丐伸手捉住了身上的虱子，骂道：老子身上没几两肉，全叫你们给咬糜了。 \n",
		(: random_move :)
	}) );
	carry_object("/obj/old_book");
}

int accept_object(object me, object obj)
{
	command("smile");
	command("say 多谢这位" + RANK_D->query_respect(me) + "，您好心一定会有好报的！");
	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "饶命！小的这就离开！\n");
	return 0;
}
