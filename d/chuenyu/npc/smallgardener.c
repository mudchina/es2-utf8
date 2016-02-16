inherit NPC;

void create()
{
        set_name("小园工", ({ "young gardener", "gardener" }) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "一位年轻的小园工\n");
        set("str", 12);
        set("int", 24);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("sword", 30);
        set_skill("parry", 30);
        set_skill("dodge", 30);

        setup();
        add_money("coin", 50);
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/scissors")->wield();
}
