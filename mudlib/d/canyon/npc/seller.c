// seller.c

inherit NPC;

void create()
{
	set_name("后备兵", ({ "guard" }) );
	set("gender", "男性" );
	set("age", 28);
	set("long",
		"环顾四方，眼神锐利，看来想杀价是不可能的事了。\n");
	set("combat_exp", 50000);
	set("attitude", "friendly");
	setup();
	
	carry_object( __DIR__"obj/blade")->wield();
}

int accept_object(object who,object ob)
{
	object obj1,obj2;



	who=this_player();
	
	if ( ob->value()==30000 ) {
		if ( this_player()->query_temp("Get_seal") ) {
			command("say 我已经给你了啊。");
			command("say 那么多钱，那我就没收了:P");
			return 1;
		}

		obj1=new(__DIR__"obj/fake_seal");
		if ( obj1->violate_unique() ) {
			command("say .......");
			command("say 内行人，你来晚一步了.. seal 被拿走了。");
			command("say 这东西你拿回去吧。");
			destruct(obj1);
			return 0;
		}

		command("say 不亏是武林中人，一眼就看出端倪了");
		command("say 这个印鉴就看在钱的份上和你交换了");
		obj1=new(__DIR__"obj/fake_seal");
		obj1->move(who);
        this_player()->set_temp("Get_seal", 1);
		return 1;
	}
	
	if ( !query_temp("check") ) {
		if ( ((string)ob->name() == "印鉴") && 
		     who->query_temp("将军/kick") ) {
			command("say 好吧！即然被你发现了，只好认栽了。");
			command("say 这个真的你就拿去吧");
			obj2=new(__DIR__"obj/seal");
			obj2->move(who);
			who->delete_temp("将军/kick");
			set_temp("check", 1);
			return 1;
		} else {
			command("say 你给我这个做什么？我不要，你拿回去吧。");
			return 0;
		}
	} 
	command("say 如果是钱的话，我先没收了。");
	command("say 其他的东西我都不要，别再来烦我了。");
	return 0;
}
			
	
