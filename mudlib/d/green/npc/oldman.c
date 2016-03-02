inherit NPC;
 
void create()
{
        int has_game;
        seteuid(getuid());
        set_name("老公公",({"old man", "oldman", "man"}));
        set("long", @TEXT
TEXT
        );
        set("gender","男性");
        set("age",77);
        set("combat_exp",70);
	set("max_gin",100);
	set("max_kee",200);
	set("max_sen",70);
        set("attitude","friendly");
        set("chat_chance_combat",50);
        set("chat_msg_combat", ({
        (: this_object(), "ask_for_help" :),
        (: this_object(), "wield_something" :) }) );
        setup();
        carry_object("/obj/cloth")->wear();
        carry_object("/obj/example/dagger");
        add_money("coin",100);
}
 
void wield_something()
{
	if (!query_temp("weapon")) command("wield dagger");
        return;
}
 
void ask_for_help()
{
        object helper;
        helper = present("old woman", environment(this_object()));
        if (!helper || helper->is_fighting()) return;
	tell_room(environment(helper), helper->name()+"喊道: "+
	"老公我来帮你了!\n", ({this_object(), helper}) );
        helper->kill_ob(query_temp("killer"));
        return;
}
 
void kill_ob(object ob)
{
        set_temp("killer",ob);
        ::kill_ob(ob);
}
