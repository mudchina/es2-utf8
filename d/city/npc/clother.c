// clother.c
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("老板娘", ({ "woman" }) );
        set("title", "绸缎庄");
        set("gender", "女性" );
        set("age", 29);
//        set("long", "李掌柜是不难看的女人，一直经营着祖传鞋店生意。\n");
        set("combat_exp", 300000);
        set("attitude", "friendly");
        set("max_atman", 1000); 
        set("atman", 1000);        
        set("atman_factor", 3);
        set("max_force", 1000); 
        set("force", 1000);
        set("force_factor", 3);
        set("max_mana", 1000); 
        set("mana", 1000); 
        set("mana_factor", 3);
        
        set_skill("dodge", 120);
        set_skill("sword", 120);
        set_skill("force", 120);
        set_skill("fonxanforce", 100);
        set_skill("fonxansword", 100);
        set_skill("chaos-steps", 100);
        map_skill("force", "fonxanforce");
        map_skill("dodge", "chaos-steps");
        map_skill("sword", "fonxansword");

        set("inquiry", ([
                "here": "这里是京师绸缎庄，没钱别进来！\n",
                "name": "在下谐陶，闺名不能告诉你。\n",
                "衣服": "您需要什么样的？",
        ]) );
        
        set("vendor_goods", ([
                "轻罗绸衫": __DIR__"obj/lady_dress",
                "淡青长袍": __DIR__"obj/green_cloth",
                "艳红绸衫": __DIR__"obj/color_cloth",
        ]) );

        setup();
        add_money("gold", 9);
        add_money("coin", 300);
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/wuqing_sword")->wield();
}

void init()
{
        object ob;

        ::init();
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
                        say( "老板娘道：这位"
                                + RANK_D->query_respect(ob)
                                + "，您需要什么？\n");
                        break;
                case 1:
                        say( "老板娘神秘地对你说：要南大食堂磁卡吗？\n");
                        break;
                case 2:
                        say( "老板娘悄声说道：奴家可是湖南人哦。\n");
                        break;
        }
}

