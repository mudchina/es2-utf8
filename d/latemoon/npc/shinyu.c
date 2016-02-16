inherit NPC;

#include <ansi.h>
 
void create()
{
        set_name("阮欣郁", ({ "shinyu","shin" }) );
        set("title", "晚月庄第三代弟子");
        set("gender", "女性" );
        set("age",17);
        set("long", @TEXT
TEXT
);
       set("class", "dancer");
        set("combat_exp", 5000000);
        set_skill("unarmed",20);
        set_skill("dodge", 100);
        set_skill("spring-blade", 100);
        set_skill("blade",100);
        map_skill("blade", "spring-blade");
        set_skill("force",100);
//
        set_skill("force",100);
        set("force",4500);
        set("max_force",4500);
        set("force_factor",20);
        set("attitude", "friendly");
        setup();
//carry_object("/u/s/seraph/latemoon/obj/yu_blade")->wield();
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
	if ((string)ob->query("gender") == "男性" ) {
		say( HIY "欣郁大喊： 喂! 兄台! 这不准男人进来! \n"  NOR );
		say( HIR "欣郁从袖里取出一把粉红色细粉泼撒出去。\n" NOR );
		say( HIY "欣郁一脚往闯入者踢了出去。\n" NOR );
        command("close door");
		ob->receive_damage("gin",50);
		ob->receive_damage("kee",100);
        ob->receive_damage("sen", 50);
		ob->move("/d/latemoon/room/flower1");
		return;
	}
    command("close door");
    return;
}

