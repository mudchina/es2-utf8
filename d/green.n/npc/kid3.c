// Mon  08-21-95

inherit NPC;
void create()
{
	seteuid(getuid());
        set_name("小孩",({"kid","child"}));
        set("gender","女性");
        set("age",random(8)+8);
        set("combat_exp",random(5)+6);
        set("attitude","friendly");
        set_temp("apply/dodge",random(3)+3);
        set("chat_chance",5);
        set("chat_msg",({
                (: this_object(), "random_move" :),
                }) );
        setup();
	carry_object("/obj/cloth")->wear();
	add_money("coin",random(10)+10);
}
