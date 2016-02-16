// Mon  08-21-95

inherit NPC;

void wield_weapon();
void converse_one();

void create()
{
        seteuid(getuid());
        set_name("妇人",({"woman"}));
        set("gender","女性");
        set("age",(random(30)+12));
        set("combat_exp",(20+random(40)));
        set_temp("apply/dodge",(10+random(5)));
        add_money("coin",90);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        (: wield_weapon :),
        (: converse_one :) }) );
        setup();
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/ricewine");
        carry_object(__DIR__"obj/knife");
}

void wield_weapon()
{
    if (!query_temp("weapon")) {
        command("say 没见识过我的菜刀神功\是吧, 接招!");
        command("wield knife");
        set("chat_chance_combat", 10);
    }
        return;
}

void converse_one()
{
    object ob;
    ob = this_player();
    if ((int)ob->query("age") < (int)query("age")) {
        command("say 死小孩, 专们欺负老人家!");
        command("slap "+(string)ob->query("id"));
    }
    else
        command("say 以大欺小啊你...");
    return;
}

