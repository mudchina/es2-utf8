inherit NPC;
void create()
{
        seteuid(getuid());
        set_name("小孩",({"kid","child"}));
        set("gender", (:(random(50)>20)? "男性" : "女性" :) );
        set("age",(random(3)+6));
        set("combat_exp",(random(10)+10));
        set("attitude", "friendly" );
        set_temp("apply/dodge",(random(2)+4));
        set("chat_chance",10);
        set("chat_msg",({
                "小孩很好奇地往门缝里看去。\n",
                "小孩说道：村长说这道门绝对不可以打开喔!\n",
                "小孩说道：不知道里面是什么...\n",
                }) );
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin",(random(10)+10));
}
 
