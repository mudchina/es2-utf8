// herbalist.c

inherit NPC;
inherit F_VENDOR;

string heal_me(object me);

void create()
{
	set_name("杨掌柜", ({ "herbalist yang", "yang" }) );
	set("title", "桑邻药铺");
	set("gender", "男性" );
	set("age", 54);
	set("long",
		"杨掌柜是这附近相当有名的大善人，常常施舍草药给付不起药钱的穷人\n"
		"。此外他的医术也不错，年轻时曾经跟著山烟寺的玄智和尚学医，一般\n"
		"的伤寒小病直接问他开药吃比医生还灵。\n" );
	set("combat_exp", 1300);
	set("attitude", "friendly");

	set("max_gin", 200);
	set("max_kee", 400);
	set("max_sen", 300);

	set("inquiry", ([
		"治伤": (: heal_me :),
		"疗伤": (: heal_me :),
		"开药": (: heal_me :),
	]) );
/*	set("vendor_goods", ([
		"人参" :		__DIR__"obj/ginseng", 
		"雪莲" :		__DIR__"obj/ice_lotus",
		"灵芝" :		__DIR__"obj/agaric",
	]) );
*/      
        set("vendor_goods", ([
                "金疮药": "/obj/drug/hurt_drug",
                "蛇药": "/obj/drug/snake_drug",
        ]) );

	set_skill("literate", 70);
	set_skill("dodge", 60);
	set_skill("unarmed", 60);
	setup();
	add_money("coin", 80);
}

void init()
{
	::init();

	add_action("do_vendor_list", "list");
}

string heal_me(object me)
{
	int ratio;

	ratio = (int)me->query("eff_kee") * 100 / (int)me->query("max_kee");
	if( ratio >= 100 )
		return "这位" + RANK_D->query_respect(me) + "，您看起来气色很好啊，不像有受伤的样子。";
	if( ratio >= 95 )
		return "哦....我看看....只是些皮肉小伤，您买包金创药回去敷敷就没事了。";
	
}
