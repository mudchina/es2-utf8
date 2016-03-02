//thief.c
inherit NPC;

void create()
{
        set_name("飞贼", ({ "thief" }) );
        set("rank", "盗贼");
        set("gender", "男性" );
        set("age", 35);
        set("int", 25);
        set("con", 28);
        set("long", @LONG
    飞贼经常出没于大户人家, 因为他轻功高强, 官府也拿他没有办法。
LONG
);
        set("combat_exp", 3000);
        set("attitude", "heroism");
        set("env/wimpy", 70);

        set("chat_chance", 40);
        set("chat_msg", ({
                "飞贼说道: 小心我把你变成穷光蛋! 吓得你不禁把钱攥紧了\n",
               (: random_move :)
        }) );

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                "飞贼恶狠狠的说道: 快滚！这没你的事！",
                "飞贼喝道: 你要是敢惹我, 咱们以后可没完!"
        }) );

        set_skill("dodge", 140);
        set_skill("parry", 100);
        set_skill("unarmed", 30);
        set_skill("move", 100);
        set_skill("stealing", 70);

        setup();

        add_money("gold", 3);
        carry_object("/u/cloud/obj/cloth/black_cloth")->wear();
        set("score",-30);
}

init()
{
        //int steal_flag;
        object ob;

        ::init();

        if( interactive(ob = this_player()) && !is_fighting() ) {
                if (random((int)ob->query("kar")) < 2) {   // 偷的概率
                        remove_call_out("steal_it");
                        call_out("steal_it", 1, ob);
                }
        } else {        // 处于战斗状态则必偷
                remove_call_out("steal_it");
                call_out("steal_it", 1, ob);
        }

}

void steal_it(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        command("grin");
        command("steal silver from " + ob->query("id"));

}

int accept_fight(object me)
{
        command("say 好小子, 居然管起大爷的事来, 看招!");
        command("grin");
        kill_ob(me);
        return 1;
}

