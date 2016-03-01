// crone.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("乾瘪老太婆", ({ "crone" }) );
	set("gender", "女性" );
	set("age", 73);
	set("long",
		"这个老太婆怀中抱了个竹篓，似乎在卖什么东西，也许\你可以跟她问问\n"
		"价钱？\n");
	set("attitude", "friendly");
	set("inquiry", ([
		"年龄": "老身今年七十有八啦。\n",
		"here":	"这一带我可熟了。\n",
		"忘忧草": "老身隐隐约约地听说过什么‘草’啊，‘狮子’的，具体的也就不知了。\n",
		]) );

	set("vendor_goods", ([
		"amulet": "/d/choyin/npc/obj/amulet",
		"red guay": "/d/choyin/npc/obj/red_guay",
	]) );
	setup();
}

void init()
{	
	::init();

	add_action("do_vendor_list", "list");
}

void relay_ask(object me, string topic)
{
	command("?");
	command("say 对不起，老婆子耳背，" + RANK_D->query_respect(me) + "您是想"
		"买东西吧？这儿有价钱(list) ....\n");
	message("vision", "老太婆打开竹篓，盖\子上贴了张纸片。\n", environment(me));
}
