// hermit1.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("卖包子的", ({ "dumpling seller", "seller" }) );
	set("gender", "男性" );
	set("age", 33);
	set("long", "这个卖包子的小贩对你微微一笑，说道：热腾腾的包子，来一笼吧？\n");
	set("combat_exp", 30);
	set("attitude", "friendly");
	set("vendor_goods", ([
	//	"obj/example/dumpling" : -1,
	        "包子": "obj/example/dumpling",
           ]) );
	set("chat_chance", 15);
	set("chat_msg", ({
		"卖包子的吆喝道：包子！热腾腾的包子！\n",
	}) );
	set("inquiry", ([
		"包子" : (: do_vendor_list :),
	]) );
	setup();
}

void init()
{	
	::init();

	add_action("do_vendor_list", "list");
}

