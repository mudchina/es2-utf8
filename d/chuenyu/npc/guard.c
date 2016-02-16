#include <ansi.h>

inherit NPC;

void create()
{
        set_name("护院", ({ "castle guard", "guard" }) );
        set("long", "这是黑松堡的护院\n");
        set("attitude", "heroism");
        set("pursuer", 1);

        set("str", 27);
        set("cor", 26);
        set("cps", 25);

        set("combat_exp", 5000);

        set("chat_chance", 30);
        set("chat_msg", ({
                "护院喝道：大胆刁民，私闯民宅，该当何罪？\n",
                (: random_move :),
        }) );

        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "护院喝道：来人啦！抓小贼呀！\n",
        }) );

        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "护院喝道：来人啦！抓小贼呀！\n",
        }) );

        set_skill("unarmed", 20);
        set_skill("sword", 30);
        set_skill("parry", 70);
        set_skill("dodge", 70);
        set_skill("move", 100);

        setup();

        carry_object("/obj/cloth")->wear();
        carry_object("/obj/longsword")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                kill_ob(ob);
        }
}

