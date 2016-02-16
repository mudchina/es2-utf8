inherit NPC;
#include <ansi.h>
 
string *make_msg = ({
    HIY "筱薇微笑的看著你说：你要作竹蜻蜓呀!\n\n" NOR,
    HIY "筱薇将你给她的竹子仔细的看了一下。说道：不错是根玉竹! \n\n" NOR,
    HIY "筱薇将竹子周围的叶子弄掉，灵巧的削凿著。\n\n" NOR,
    HIY "经过不久，筱薇把竹蜻蜓做好了。\n\n" NOR,
    HIY "筱薇将做好的竹蜻蜓递给你，微笑说道：嗯! 做好了! \n\n" NOR,
});

void create()
{
        set_name("蓝筱薇", ({ "shao-wei","shaowei","wei"  }) );
        set("gender", "女性" );
        set("age",18);
        set("long", @TEXT
她长得十分漂亮！让你忍不住多瞧她几眼，从她身上
你闻到淡淡的香气。她很有礼貌的向你点头，优雅的
动作，轻盈的步伐，好美哦!
她是晚月庄主蓝止萍的养女。
TEXT
);
       set("class", "dancer");
       set("combat_exp", 200000);
        set_skill("unarmed",70);
        set_skill("dodge", 80);
        set_skill("force",70);
        set_skill("sword",70);
        set_skill("stormdance", 50);
        map_skill("dodge","stormdance");
        set("force", 3000);
        set("max_force", 600);

        set("force_factor", 10);
        set("inquiry", ([
        "舞" : "我舞跳的不好!我比较喜欢静态的活动。\n",
        "竹蜻蜓" : "咦..!你也喜欢玩啊! 我会做哦! \n" +
                   "不过我需要一根竹子! 你找来我帮你做! \n",
        "芳绫" : "听说她贪玩被关在禁闭室。她最爱玩竹蜻蜓了! \n",
        ]));
        create_family("晚月庄",2,"大弟子");

        setup();
        carry_object("/d/latemoon/obj/clasp")->wear();
        carry_object("/d/latemoon/obj/deer_boot")->wear();
        carry_object("/d/latemoon/obj/skirt2")->wear();
        carry_object("/d/latemoon/obj/bamboo_sword")->wield();

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
                  say( "筱薇对你微笑，和善的对你点点头。\n");
                        break;
                case 1:
                  say( "筱薇对你微笑，以纤细轻柔的声音 \n 说道：这位" +
RANK_D->query_respect(ob)
                   + "，你好！欢迎来到晚月庄。\n");
        }
}

int accept_object(object who, object ob)
{
     string objname;
     objname = (string)ob->name();

        if ( objname != "竹子")  {
           command("smile");
            say ( HIY "这要送给我啊?! 怎么好意思!谢谢你。\n" NOR);
           command("blush");
             return 1;
            }
        if( !who->query_temp("moon/竹子") )  {
          call_out( "make_stage", 2, who, 0 );

            who->set_temp("moon/竹子", 1);
         } else {
             say (HIY "我已经帮你做一个竹蜻蜓了呀! \n" NOR);
             return 1;
          }
          return 1;
}
void make_stage(object who, int stage)
{
     object obj;
     tell_object(who, make_msg[stage]);
     if( ++stage < sizeof(make_msg) ) {
         call_out( "make_stage", 2, who, stage );
         return;
     } else
       obj = new("/d/latemoon/obj/dragonfly");
       obj->move(who);
    return;
}
