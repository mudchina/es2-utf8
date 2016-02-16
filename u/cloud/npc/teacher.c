// butcher.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("郑屠夫", ({ "butcher", "zheng" }) );
        set("title", "镇北肉铺");
        set("gender", "男性" );
        set("age", 35);
        set("long", "你看到一个剽悍的大块头, 正在用钢刀剔牛骨。\n");
	set("str", 29);
	set("int", 14);
        set("combat_exp", 2500);
        set("attitude", "heroism");
        set_skill("unarmed", 100);
        set_skill("parry", 80);

        set("inquiry", ([
		"碧玉刀" : "这刀可是个宝物, 据说是当年张家老祖宗退隐时皇上赐的。",
		"香茗坊" : "您也知道'碧海银针'？茶楼就在街对面，我常去的。", 
        ]) );

        set("vendor_goods", ([
                "牛肉": "/u/cloud/obj/meat/b_beef",
		"牛腿": "/u/cloud/obj/meat/hind",
		"牛尾": "/u/cloud/obj/meat/tail",
		"杂碎": "/u/cloud/obj/meat/zasui",
                "狗肉": "/u/cloud/obj/meat/dog_m.c",
        ]) );

	setup();
	add_money("silver", 12);
	add_money("coin", 500);
        carry_object("/obj/cloth")->wear();
	carry_object("/u/cloud/obj/npc/butcher/knife");
	carry_object("/u/cloud/obj/npc/butcher/skin_belt")->wear();
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
        switch( random(4) ) {
                case 0:
                        say( "屠夫边剔骨头边嘟囔着：真是好刀，剔得好舒服! \n");
                        break;
                case 1:
                        say( "屠夫摇摇头, 叹了口气说：唉, 不知那碧玉刀究竟"
				+"比我这刀厉害几倍...\n");
                        break;
                case 2:
                        say( "屠夫咧开大嘴, 笑着道：这位"  
				+ RANK_D->query_respect(ob)
                                + "，要买肉是吗? \n");
                        break;
                case 3:
                        say( "屠夫忙着给人取肉, 似乎没注意到你进来。\n");
                        break;
        }
}

