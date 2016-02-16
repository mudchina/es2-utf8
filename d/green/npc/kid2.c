inherit NPC;
void create()
{
        seteuid(getuid());
        set_name("小孩",({"kid","child"}));
        set("gender","男性");
        set("age",(random(8)+7));
        set("combat_exp",(random(10)+5));
        set("score",(random(50)+10));
        set("attitude", (: (random(50)<25)? "peaceful" : "friendly" :));
        set_temp("apply/dodge",(random(2)+3));
        set("chat_chance",10);
        set("chat_msg",({
                (: this_object(), "random_move" :),
                }) );
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin",(random(10)+5));
}
