// monk.c

inherit NPC;
inherit F_VENDOR;

void catch_thief();

void create()
{
	set_name("瓜农", ({ "meloner" }) );
	set("gender", "男性" );
	set("age", 46);
	set("str", 29);
	set("cor", 26);
	set("cps", 29);
	set("int", 22);
	set("per", 18);
	set("spi", 23);
	set("kar", 25);
	set("con", 27);
	set("long", @LONG
一个中年瓜农，脸上被阳光晒得黝黑，一身的键子
肉，给人的感觉是扎实威猛。
LONG
);
	set("attitude", "friendly");
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
	(:catch_thief:), }) );	
	//set("inquiry", ([
//		"": "",
//	]) );

	set("vendor_goods", ([
                "water melon": "/d/village/obj/melon",
        ]) );      
        
	set("force", 500);
        set("max_force", 500);

        set("mana", 50);
        set("max_mana", 50);

        set("combat_exp", 8000);
        set("score", 100);

        set_skill("unarmed", 80);
        set_skill("force", 60);
        set_skill("dodge", 50);
        set_skill("parry", 50);
	set_skill("chaos-steps",30);
	set_skill("fonxansword",30);
	set_skill("fonxanforce",30);
	map_skill("parry", "fonxansword");
        map_skill("dodge", "chaos-steps");
	map_skill("force","fonxanforce");
	setup();

        carry_object("/obj/cloth")->wear();
//	carry_object("/obj/weapon/longsword")->wield();
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
	add_action("do_return", "return" );
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "这位" + RANK_D->query_respect(ob)
                + "要不要买个西瓜解解渴？\n");
}

int do_return(string arg)
{
	if( !this_player()->query_temp("melon/catch_thief") )
	  return notify_fail("你又没欠他什么，为什么要还？\n" );
	if(!arg) return notify_fail("你要还什么？\n");
	if( arg=="melon cost" || arg=="瓜钱" )
	{
	  command("say 好，咱俩的账就算结了。\n");
	  set_temp("melon/catch_thief",0);
	  this_player()->set_temp("melon/catch_thief",0);
	  set_leader(0);
	  move(find_object("/d/village/melonguard"));
	  return 1;
	}
	return notify_fail("除了瓜钱，我什么都不要。\n");
}

void catch_thief()
{
	if( query_temp("melon/catch_thief") )
	  command( "say 你要不还我瓜钱(return melon cost)），咱俩就没完！\n" );
	else
	  command( "heihei this_player()" );
}
