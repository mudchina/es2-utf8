// keeper.c

inherit NPC;

void create()
{
	set_name("庙祝", ({ "keeper" }) );
	set("gender", "男性" );
	set("age", 74);
	set("long",
		"这个老人看起来七十多岁了，看著他□偻的身影，你忽然觉得心情沈重了下来。\n");
	set("combat_exp", 1);
	set("attitude", "friendly");
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
}

void greeting(object ob)
{
	if( !ob || !present(ob, environment(this_object())) ) return;
	say( "庙祝说道：这位" + RANK_D->query_respect(ob)
		+ "，捐点香火钱积点阴德吧。\n");
}

/*int accept_object(object who, object ob)
{
	say( "庙祝说道：这位" + RANK_D->query_respect(who)
		+ "，请把香油钱投入功\德箱。\n");
	return 0;
}*/
int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("庙祝不收物品的捐献。\n");
        else if( val > 100 ) {
                if( (who->query("bellicosity") > 0)
                &&      (random(val/10) > (int)who->query("kar")) )
                        who->add("bellicosity", -
(random((int)who->query("kar")) + val/1000) );
        }
        say( "庙祝说道：多谢这位" + RANK_D->query_respect(who)
                + "，神明一定会保佑你的。\n");

        return 1;
}


