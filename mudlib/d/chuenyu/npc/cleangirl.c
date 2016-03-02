// worker.c

inherit NPC;

void create()
{
        set_name("女佣人", ({ "cleaning maid", "maid" }) );
        set("gender", "女性" );
        set("age", 43);
        set("long", "满脸风霜的女佣人\n");
        set("combat_exp", 700);
        set("attitude", "friendly");
        set_skill("unarmed", 10);
        set_skill("parry", 25);
        set_skill("dodge", 35);
        set_skill("throwing", 20);

        set("inquiry", ([
                "小娟" : "这要到地牢去找。", 
                "淳于" : "这要到地牢去找。",
                "淳于怀太" : "这要到地牢去找。",
                "堡主" :"这要到地牢去找。",
        ]) );

        setup();
        add_money("coin", 15);
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/feather")->wield();
}

