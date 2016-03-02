inherit NPC;
#include <ansi.h>
 
void create()
{
         set_name("凤凰", ({ "phoenix","fire" }) );
        set("title", "护庄神像");
        set("nick","火神");
        set("gender", "女性" );
        set("age", 27);
        set("long", @TEXT
火神「凤凰」乃勇士寒于的魂魄所化成的十三个精灵之一。
由于其奇异神迹，被晚月庄供奉为护庄神兽。
TEXT
);
        set("combat_exp", 50000000);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("tenderzhi", 100);
        set_skill("iceforce", 100);
        set_skill("stormdance", 100);
        set_skill("force",100);
        map_skill("force","iceforce");
        map_skill("dodge","stormdance");
        map_skill("unarmed","tenderzhi");
        set("force", 7000);
        set("max_force", 7000);
        set("force_factor", 30);
        set("attitude", "friendly");
         set_temp("apply/armor", 100);
        
        setup();
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
          say( HIY "神像眼神骤变，幻化成七彩凤凰，出现金色光芒。\n" NOR);
          kill_ob(ob);
          ob->fight_ob(this_object());
          return;
    }
}

