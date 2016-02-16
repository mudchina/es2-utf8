// cucurbit_seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("卖糖葫芦的", ({ "cucurbit chapman", "chapman" }) );
	set("gender", "男性" );
	set("age", 42);
	set("combat_exp", 30);
	set("attitude", "friendly");
	set("vendor_goods", ([
	      "糖葫芦":__DIR__"obj/cucurbit",
	]) );
	set("chat_chance", 15);
	set("chat_msg", ({
		"卖糖葫芦的吆喝道：糖葫芦！好甜好香的糖葫芦！\n",
	}) );
	set("inquiry", ([
		"糖葫芦" : (: do_vendor_list :),
	]) );
	setup();
}

void init()
{	
	::init();

	add_action("do_vendor_list", "list");
}

