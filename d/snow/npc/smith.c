// smith.c

inherit NPC;

void create()
{
	set_name("王铁匠", ({ "wang", "smith" }) );
	set("gender", "男性" );
	set("age", 33);
	set("long", "王铁匠正用铁钳夹住一块红热的铁块放进炉中。\n");
	set("combat_exp", 400);
	set("inquiry", ([
		"name": "小人姓王，单名一个恒字，可是小人西瓜大的字识不到一担，只有王字会写。\n",
		"here": "这里是小人糊口的铺子，小人一家五口都住在后边的屋子。\n",
		"锄头": "锄头... 抱歉，锄头已经卖光了...\n",
		"铲子": "对不起，小人店里的铲子都给人订走了。\n",
		"铁锤": "铁锤？小人做的铁锤坚固又耐用，一把只要三百文钱。\n"
	]) );
	setup();
	carry_object(__DIR__"obj/hammer")->wield();
}

int buy_object(object who, string what)
{
	if( what=="铁锤" ) return 300;
	return 0;
}

void compelete_trade(object who, string what)
{
	object ob;

	ob = new(__DIR__"obj/hammer");
	ob->move(who);
	message_vision("$N交给$n一把沈甸甸的打铁用铁锤。\n", this_object(), who);
}
