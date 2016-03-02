// room_guard.c
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("保镖", ({ "guard" }) );
        set("title", "贴身保镖");
        set("gender", "男性" );
        set("age", 25);
        set("long", "你看到一个剽悍的大块头。\n");
        set("str", 29);
        set("int", 14);
	set("cor", 56);
	set("max_kee",800);
        set("combat_exp", 10000);
        set("attitude", "heroism");
        set_skill("unarmed", 200);
        set_skill("parry", 140);
        set_skill("dodge", 220);

        set("inquiry", ([
                "碧玉刀" : "这刀可是个宝物, 
据说是当年张家老祖宗退隐时皇上赐的。",
                "镇关西" : "这雪亭镇有谁不知道我家老爷镇大官人！",
        ]) );
        setup();
        add_money("silver", 12);
        add_money("coin", 500);
        carry_object("/obj/cloth")->wear();
}

