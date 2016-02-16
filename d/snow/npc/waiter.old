// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("店小二", ({ "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 5);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ([
		"/obj/example/dagger": 1,
		"/obj/example/wineskin": -1,
		"/obj/example/dumpling": -1,
		"/obj/example/chicken_leg": -1,
	]) );
	setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
			say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝杯茶，歇歇腿吧。\n");
			break;
		case 1:
			say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break;
		case 2:
			say( "店小二说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝几盅小店的红酒吧，这几天才从窖子里开封的哟。\n");
			break;
	}
}

/*
void relay_say(object ob, string msg)
{
	object cake;

	if( (strsrch(msg,"ES2")>=0 || strsrch(msg, "es2")>=0) && strsrch(msg,"生日快乐")>=0 ) {
		command("jump");
		command("say 生日快乐!");
		seteuid(getuid());
		if( !present("cake", ob) ) {
			cake = new("/obj/example/cake");
			cake->move(ob);
			message_vision("$N给$n一块看起来就令人流口水的蛋糕。\n", this_object(), ob);
		}
	}
}
*/