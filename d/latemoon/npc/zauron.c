inherit NPC;
#include <ansi.h>
 

void create()
{
        set_name("昭蓉", ({ "zauron","zau","ron" }) );
        set("gender", "女性" );
        set("age",18);
        set("long", @TEXT
她长得十分漂亮！让你忍不住多瞧她几眼，从她身上
你闻到淡淡的香气。她很有礼貌的向你点头，优雅的
动作，轻盈的步伐，好美哦!
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
        "芳绫" : "听说她贪玩被关在禁闭室。她最爱玩竹蜻蜓了! \n",
        ]));
        create_family("晚月庄",2,"弟子");

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
                  say( "昭蓉对你微笑，和善的对你点点头。\n");
                        break;
                case 1:
                  say( "昭蓉对你微笑，以纤细轻柔的声音 \n 说道：这位" +
RANK_D->query_respect(ob)
                   + "，你好！欢迎来到晚月庄。\n");
        }
}

