inherit NPC;

void create()
{
        set_name("紫衣童子", ({ "boy" }) );
        set("gender", "男性" );
        set("age", 15);
        set("per", 30-random(15) );
        set("long",@LONG
紫衣童子是乔阴县的小孩，从小孤苦零丁。仙人怜之，带入云台。
LONG
        );
        set("combat_exp", 1200000);
        set("attitude", "friendly");
                set("chat_chance", 2);
        set("chat_msg", ({
"紫衣童子躬身一揖。 \n",
"童子说道：仙人 ，只在此山中，云深不知处。\n", 
       }) );

                set("chat_chance_combat", 10);
                set("chat_msg_combat", ({
"紫衣童子拧眉说道：你欺负我年纪小是吗？\n",
"紫衣童子笑道：你杀不死我的。\n",
"紫衣童子冲你一龇牙, 说道: 您盗过古墓吗?\n",
                }) );
        set("inquiry", ([
                "仙人" : "只度有缘人。",
        ]) );

        set_skill("dodge", 150);
        set_skill("unarmed", 150);
        set_skill("mysterrier",150); 
        map_skill("dodge", "mysterrier");
        set_skill("force", 15);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 0);
        setup();

}

