//vendor.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("卖艺壮汉", ({ "vendor man","man" }) );
        set("gender", "男性" );
        set("age", 34);
        set("long", "一个满脸横肉的壮汉，口水四溅，正说着什么。\n");
        set("combat_exp", 30000);
        set("attitude", "friendly");
        set("vendor_goods", ([
                "金疮药": "/obj/drug/hurt_drug",
        ]) );
        set("chat_chance", 20);
        set("chat_msg", ({
                "卖艺壮汉吆喝道：出外靠朋友，诸位请捧个钱场！\n",
                "卖艺壮汉练了一套六阴剑，还象模象样。\n",
                "卖艺壮汉低声对你说道：在下刚路过八舍！\n",
        }) );
        set("inquiry", ([
                "金疮药" : (: do_vendor_list :),
        ]) );
        setup();
}

void init()
{
        ::init();

        add_action("do_vendor_list", "list");
}

