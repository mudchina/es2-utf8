inherit NPC;
 
void create()
{
         set_name("苗郁淑", ({ "yushou","yu","shou" }) );
        set("gender", "女性" );
        set("age",18);
        set("long", @TEXT
她看起来很有活力，两眼明亮有神。给你
一种巾帼不让须眉的气势，但刚毅之中似
又隐含著女孩子有的娇柔。
TEXT
);
       set("class", "dancer");
       set("combat_exp", 15000);
        set_skill("unarmed",40);
        set_skill("dodge", 40);
        set_skill("stormdance", 50);
        set_skill("tenderzhi", 60);
        set_skill("force",50);
        map_skill("dodge","stormdance");
        map_skill("unarmed","tenderzhi");
        set("force", 400);
        set("max_force", 400);
        set_temp("apply/armor", 100);

       create_family("晚月庄",3,"弟子");
        setup();
        carry_object(__DIR__"obj/earring")->wear();
        carry_object(__DIR__"obj/brooch")->wear();
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
        command("close door");
        say ("阁下! 这里是庄内后厅厢房。不方便男客进入哦! \n" +
              "请随手关门，并保持安静! 谢谢! \n" );
}
