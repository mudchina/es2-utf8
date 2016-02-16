// doctor.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("伙计", ({ "waiter" }) );
        set("title", "药店");
        set("gender", "男性" );
        set("age", 17);
        set("long", "药店的小伙计，正在学着配药。\n");
        set("combat_exp", 100);
        set("attitude", "heroism");
        set_skill("unarmed", 30);
        set_skill("parry", 10);
        set_skill("dodge", 10);

        set("inquiry", ([
		"抓药" : "这里是附近最好的药店，您要什么？",
        ]) );

        set("vendor_goods", ([
                "金疮药": "/obj/drug/hurt_drug",
		"蛇药": "/obj/drug/snake_drug",
	//	"人参": "/u/cloud/obj/meat/tail",
	//	"何首乌": "/u/cloud/obj/meat/zasui",
        ]) );

	setup();
	add_money("coin", 50);
        carry_object("/obj/cloth")->wear();
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
                        say( "小伙计称了几味药，包做个纸包。\n");
                        break;
                case 1:
                        say( "伙计点头道：这位"  
				+ RANK_D->query_respect(ob)
                                + "，买药？\n");
                        break;
        }
}

