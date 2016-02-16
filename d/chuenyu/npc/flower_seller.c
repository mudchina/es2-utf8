// worker.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("卖花姑娘", ({ "flower seller", "seller" }) );
        set("gender", "女性" );
        set("age", 19);
        set("per", 40);
        set("long", "美丽的卖花姑娘正在向行人售花儿\n");
        set("combat_exp", 700);
        set("attitude", "friendly");
        set_skill("unarmed", 40);
        set_skill("parry", 25);
        set_skill("dodge", 150);
        set_skill("throwing", 100);

        set("inquiry", ([
                "小娟" : "这要到黑松山去问。", 
        ]) );
        set("chat_chance", 5);
        set("chat_msg", ({
                (:random_move :)
        }) );
        set("vendor_goods", ([
                "紫罗兰": __DIR__"obj/purple_flower",
                "红玫瑰": __DIR__"obj/red_flower",
                "黄玫瑰": __DIR__"obj/yellow_flower",
                "蓝天鹅": __DIR__"obj/blue_flower",
                "白茶花": __DIR__"obj/white_flower",
                "黑牡丹": __DIR__"obj/black_flower",
        ]) );

        setup();
        add_money("silver", 15);
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/flower")->wield();
        carry_object(__DIR__"obj/flower")->wield();
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
        switch( random(6) ) {
                case 0:
                        say( " 卖花姑娘笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，买朵黑牡丹吗？ \n");
                        break;
                case 1:
                        say( " 卖花姑娘笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，买朵黄枚瑰吗？ \n");
                        break;
                case 2:
                        say( " 卖花姑娘笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，买朵白茶花吗？ \n");
                        break;
                case 3:
                        say( " 卖花姑娘笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，买朵紫罗兰吗？ \n");
                        break;
                case 4:
                        say( " 卖花姑娘笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，买朵红枚瑰吗？ \n");
                        break;
                case 5:
                        say( " 卖花姑娘笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，买朵黄枚瑰吗？ \n");
                        break;

        }
}


