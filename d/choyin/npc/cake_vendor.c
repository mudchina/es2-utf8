// cake_vendor.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("卖饼大叔", ({ "cake vendor", "vendor" }) );
	set("gender", "男性" );
	set("age", 42);
	set("long", "一个相貌朴实的卖饼大叔，憨厚的脸上挂著和蔼的笑容。\n");
	set("combat_exp", 30);
	set("attitude", "friendly");
	set("rank_info/respect", "大叔");
	set("rank_info/self", "小的");
	set("vendor_goods", ([
              "大饼": __DIR__"obj/cake",
	]) );
	set("chat_chance", 13);
	set("chat_msg", ({
		"卖饼大叔吆喝道：卖饼哟！又香又脆的大饼哟！\n",
		"卖饼大叔掀开蒸笼，伸手探了探温度。\n",
		"卖饼大叔吆喝道：刚出炉的大饼哟！热呼呼的大饼哟！\n",
	}) );
	set("inquiry", ([
		"大饼" : (: do_vendor_list :),
	]) );
	setup();
}

void init()
{	
	::init();

	add_action("do_vendor_list", "list");
}

