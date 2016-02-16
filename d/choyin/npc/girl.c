// girl.c

inherit NPC;

string ask_youngman();

void create()
{
	set_name("官家小姐", ({ "girl" }) );
	set("long", "一个看起来像是有钱人家的女子，正在这里游湖。\n");
	set("age", 23);
	set("gender", "女性");
	set("attitude", "peaceful");
	set("combat_exp", 10);
	set("env/wimpy", 100);
	set("inquiry", ([
		"name": "我 ... ？ 你们外地人都做兴这么问陌生姑娘的闺名吗？",
		"here": "这里啊？这里就是乔阴县有名的翠柳湖啊！",
		"闺名": "真是没有礼貌的家伙，我才不告诉你！",
		"游晋" : (: ask_youngman :), 
	]) );
	setup();
	carry_object(__DIR__"obj/lady_dress")->wear();
	carry_object(__DIR__"obj/silver_clasp")->wear();
}

string ask_youngman()
{
	object bag, me;

//	if( !me = query_temp("last_asker") ) return "您说的是 ... 游尚书游大人府上的游 ... 游相公吗？\n";

	bag = new(__DIR__"obj/silk_bag");
	bag->move(this_player());
        return "小女子有一事相求 ... 请您将这个交给游 ... 游公子。\n";
        delete("inquiry/游晋");
}

