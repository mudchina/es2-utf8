inherit NPC;
void create()
{
        seteuid(getuid());
        set_name("测试用的小孩 - 不准杀!!!!",({"kid","child"}));
        set("gender","男性");
        set("age",(random(8)+7));
        set("combat_exp",99999999);
        set("attitude", "friendly");
	set_temp("apply/attack",1000);
        set_temp("apply/dodge",1000);
	set_temp("apply/unarmed",1000);
        set("chat_chance",40);
        set("chat_msg",({
                (: this_object(), "random_move" :),
                }) );
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin",(random(10)+5));
}

void kill_ob(object ob)
{

	ob->set_temp("last_damage_from", this_object());
	ob->die();
	return;
}

