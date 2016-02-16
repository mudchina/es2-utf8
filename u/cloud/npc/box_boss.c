// box_boss.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("林三爷", ({ "boxboss", "lin" }) );
        set("title", "棺材铺老板");
        set("gender", "男性" );
        set("age", 55);
        set("long", "这位面目慈善的老人经营棺材铺已经有很多年了。\n");
        set("str", 29);
        set("int", 14);
	set("max_kee",800);

        set("combat_exp", 2000);
        set("attitude", "heroism");
        set_skill("unarmed", 60);
        set_skill("parry", 60);
        set_skill("dodge", 70);
	set_temp("apply/armor",20);

        set("inquiry", ([
                "棺材" : "您这么年轻就要棺材，早了点吧？",
                "香茗坊" : "您也知道'碧海银针'？茶楼就在街对面，我常去的。", 
        ]) );

        setup();
        add_money("silver", 4);
        add_money("coin", 100);
        carry_object("/obj/cloth")->wear();
}

