inherit NPC;
 
void create()
{
        object ob;

        set_name("蓝小蝶", ({ "shao-de" }) );
        set("gender", "女性" );
        set("age",18);
        set("long", @TEXT
她长得十分漂亮！让你忍不住多瞧她几眼，从她身上
你闻到淡淡的香气。她很有礼貌的向你点头，优雅的
动作，轻盈的步伐，好美哦!
她是晚月庄主蓝止萍的养女，平常庄内的接待是看她。
TEXT
);
       set("class", "dancer");
       set("combat_exp", 60000);
       set("potential", 200);
        set("kee",350);
        set("san",100);
        set_skill("unarmed",60);
        set_skill("dodge", 50);
        set_skill("force",50);
       set("force", 2000);
       set("max_force", 2000);
       set("force_factor",2);
       set_temp("apply/armor", 50);
       create_family("晚月庄",3,"大弟子");

        setup();
        ob = carry_object(__DIR__"obj/needle");
        ob->set_amount(30);
        carry_object(__DIR__"obj/deer_boot")->wear();
        carry_object(__DIR__"obj/skirt3")->wear();
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
        switch( random(2) ) {
                case 0:
                  say( "小蝶对你微笑，和善的对你说：\n  这位" + 
RANK_D->query_respect(ob)
                   + "，你好！欢迎来到晚月庄。请坐！\n");
                        break;
                case 1:
                  say( "小蝶对你微笑，纤细的双手捧著茶，\n 说道：这位" +
RANK_D->query_respect(ob)
                   + "，你好！欢迎来到晚月庄。请用茶！\n");
        }
}
