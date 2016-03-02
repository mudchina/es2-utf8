// sergeant.c

inherit NPC;

int chest_found = 0;

void create()
{
	set_name("武官", ({ "sergeant" }) );
	set("long",
		"一位相貌威武的武官，独自一个人站在这里发呆，似乎正有什么\n"
		"事困扰著他。\n" );
	set("age", 29);
	set("combat_exp", 250000);
	set("env/wimpy", 10);
	set("str", 28);
	set("cor", 28);
	set("cps", 28);
	set("pursuer", 1);
	set("inquiry", ([
		"name" : "在下姓陈，名显祖，阁下是？",
		"here" : "真是不巧，我也是外地来的，对这个地方并不熟悉。",
		"rumors" : "在下失落了一件重要物事，是装在一个桃木箱子里，不知你有没有看见？",
		"箱子" : "对，是桃木做成的箱子。",
		"桃木箱子" : "如果你见著了，麻烦送还给我，在下定当重重报答。",
		"陈显祖" : "不敢，正是在下，不知阁下有何指教？"
	]) );
	set_skill("dodge", 70);
	set_skill("unarmed", 60);
	set_skill("parry", 70);
	set_skill("sword", 75);

	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 30);

	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/longsword")->wield();
}

int accept_object(object me, object ob)
{
	object book;

	if( !chest_found && ob->id("peach chest") ) {
		chest_found = 1;
		command("say 太好了！就是这个箱子！");
		command("say 在下出门在外，没有携带太多银两 ... ");
		command("say 如果您不嫌弃的话，这本古书便请笑纳。");
		book = new(__DIR__"obj/magic_book");
		book->move(this_object());
		command("give book to " + me->query("id"));
		delete("inquiry/rumors");
		delete("inquiry/箱子");
		delete("inquiry/桃木箱子");
		return 1;
	}
	return 0;
}
