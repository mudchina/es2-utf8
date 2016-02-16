inherit NPC;
#include <ansi.h>
 
void create()
{
        set_name("芙云", ({ "fuyun" }) );
        set("title", "晚月庄第三代弟子");
        set("gender", "女性" );
        set("age",17);
        set("long", @TEXT
TEXT
);
       set("class", "dancer");
        set("combat_exp", 5000000);
        set("score", -1000);
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
        if( !ob || !present(ob, environment(this_object())) ) return;
     if ((string)ob->query("gender") == "男性" ) {
          say( HIY "芙云惊慌生气的怒斥： 喂! 色狼! 这不准男人进来!\n" NOR);
          kill_ob(ob);
          ob->fight_ob(this_object());
          return;
    }
}

