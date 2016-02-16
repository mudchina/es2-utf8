// banker.c

#include <ansi.h>

inherit NPC;

string ask_me(object who);
void greeting(object ob);

void create()
{
	set_name("故事", ({ "chp" }) );
//	set("title", "板");
	set("gender", "男性" );
	set("age", 26);

	set("str", 22);
	set("cor", 30);
       set("cps", 30);
	set("int", 26);
	set("per", 23);
	set("con", 24);
	set("long", "故事是个看起来相当斯文的年轻人，不过有时候会有些心不在焉的\n"
                "样子，颇有些隐者的风骨\n");
set("combat_exp", 200000);
	set("attitude", "friendly");
	set("pursuer", 1);
	set("env/wimpy", 70);

	set("max_atman", 1000);		set("atman", 1000);		set("atman_factor", 3);
	set("max_force", 1000);		set("force", 1000);		set("force_factor", 3);

        set("chat_chance_combat", 40);
	set("max_mana", 1000);		set("mana", 1000);		set("mana_factor", 3);

        set("chat_msg_combat", ({
                CYN "故事似笑非笑地望著你，脸上的神气古理古怪，不知道在想些什
么？\n" NOR,
                CYN "故事的身影晃了一下，似乎在你身上各处大穴摸了一下，不过也
许\是你的错觉。\n" NOR,
                CYN "故事神情忽然严肃了起来，不过好像是在想自己的英语翻译事，与你无关
。\n" NOR,
                CYN "故事忽然呵呵呵地笑了起来，却不知道在笑些什么....\n" NOR,
                (: perform_action, "sword.counterattack" :),
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
                
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("force", 100);
	set_skill("celestrike", 100);
	set_skill("celestial", 100);
	set_skill("fonxansword", 100);
	set_skill("six-chaos-sword", 100);
	set_skill("chaos-steps", 100);
	set_skill("spells", 100);
	set_skill("necromancy", 100);

	map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");
	map_skill("dodge", "chaos-steps");
	map_skill("sword", "fonxansword");
	map_skill("spells", "necromancy");
	map_skill("sword", "fonxansword");
	
	setup();
	
	carry_object("/obj/longsword")->wield();
	carry_object("/obj/cloth")->wear();

	//add_money("gold", 10);
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "故事笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来歇息一下吧。\n");
                        break;
                case 1:
                        say( "故事用毛巾抹了抹头上的汗，说道：这位" + RANK_D->query_respect(ob)
                                + "，帮我翻译几页英文资料吧。\n");
                        break;
                case 2:
                        say( "故事说道：这位" + RANK_D->query_respect(ob)
                                + "，有什么意见可以提呀。\n");
                        break;
        }
}

int accept_fight(object me)
{
	command("say 咦... 要打就真打吧，光是较量多没意思？");
	command("grin");
	kill_ob(me);
	return 1;
}
