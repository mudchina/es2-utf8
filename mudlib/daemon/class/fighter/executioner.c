// executioner.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("潘军禅", ({ "master executioner", "executioner", "master" }) 
);
        set("title", "水烟阁执法使");
        set("nickname", HIC "书 剑 侠" NOR);
        set("gender", "男性");
        set("age", 28);
        set("long",
                
"潘军禅是当今武林的一位传奇性人物，以他仅仅二十八岁的年龄竟能做到\n"
                
"水烟阁执法使的职位，著实是一位不简单的人物。潘军禅是封山剑派掌门\n"
                
"柳淳风的结拜义弟，但是他为人其实十分风趣，又好交朋友，丝毫不会摆\n"
                "出武林执法者的架子。\n" );

        set("attitude", "friendly");
        set("combat_exp", 1000000);
        set("score", 200000);

        set("str", 30);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);

        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 2);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);

        set_skill("celestial", 100);
        set_skill("celestrike", 100);
        set_skill("pyrobat-steps", 100);
        set_skill("six-chaos-sword", 100);

        map_skill("force", "celestial");
        map_skill("unarmed", "celestrike");
        map_skill("sword", "six-chaos-sword");
        map_skill("dodge", "pyrobat-steps");

        setup();

        carry_object(__DIR__"soulimpaler")->wield();
}

 
