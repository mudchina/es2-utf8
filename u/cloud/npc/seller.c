// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("杂货贩", ({ "seller" }) );
        set("title", "杂货铺");
        set("gender", "男性" );
        set("age", 32);
        set("long", "卖杂货的是个年轻汉子，面带微笑。\n");
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set_skill("unarmed", 60);
        set_skill("dodge", 50);
        set_skill("throwing", 30);

        set("inquiry", ([
                "杂货铺" : "这是祖上传下来的产业，小的在勉力维持。", 
        ]) );

        set("vendor_goods", ([
                "麻绳": "/u/cloud/obj/etc/rope",
 //               "布袋": "/obj/example/bag",
                "化尸粉": "/obj/dust",
//"/u/cloud/obj/etc/dust",
        ]) );

        setup();
        add_money("silver", 5);
        add_money("coin", 300);
        carry_object("/obj/cloth")->wear();
        for(int i=1; i<=29; i++){
        carry_object("/obj/example/dart")->wield();
        }
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

        if(random(10)<5)
                carry_object("/obj/example/dart")->wield();

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 0:
                        say( "杂货贩笑脸相迎，道：这位"
                                + RANK_D->query_respect(ob)
                                + "，要买什么？\n");
                        break;
                case 1:
                        say( "杂货贩正忙着整理货架\n");
                        break;
        }
}

