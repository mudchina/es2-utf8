inherit NPC;
#include <ansi.h>
 
void create()
{
        set_name("虞琼衣" , ({ "chungyu","chung","yu" }) );
        set("title", "晚月庄弟子");
        set("gender", "女性" );
        set("age",17);
        set("long", @TEXT
TEXT
);
       set("class", "dancer");
        set("combat_exp", 40000);
        set_skill("unarmed", 70);
        set_skill("dodge", 70);
        set_skill("stormdance", 50);
          set_skill("tenderzhi", 70);
         map_skill("dodge","stormdance");
         map_skill("unarmed","tenderzhi");
        set_skill("force",100);
        set("force", 900);
        set("max_force",450);
        set("force_factor", 5);
        set_temp("apply/armor", 70);
        setup();
        carry_object("/d/latemoon/obj/skirt3")->wear();
        add_money("silver", 1);
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
          say( HIY "琼衣很礼貌的向你微笑! \n" NOR);
          say ( HIY "说道：请保持安静哦! \n" NOR);
          ob->receive_damage("sen", 10);
          this_object()->add("force", 50);
          command("close door");
          return;
    }
       command("close door");
       return;
}

