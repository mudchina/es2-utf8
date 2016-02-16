inherit NPC;
 
void cancel_give();
void start_give();
void set_flag();
 
void create()
{
        seteuid(getuid());
        set_name("村长", ({"elder", "oldman", "man"}));
        set("long", @TEXT
TEXT
        );
        set("gender","男性");
        set("age",95);
	set("max_gin",100);
	set("max_kee",200);
	set("max_sen",100);
        set("combat_exp",500);
        set("attitude","friendly");
        set("chat_chance",10);
        set("inquiry", ([
        "玉佩" : ({
            "嗯...... 你是说那个从古墓盗出来的玉佩?\n",
            "应该蛮珍贵的, 可是有点来路不明...\n",
            "我送给一个年轻人了, 不过听说他得此玉佩后性情大变.\n",
            "看来此物不祥... \n",
            "你要找他吗? 有人说他现在以酒度日, 我也不知他的下落.\n",
            (: command, "shrug" :),
            (: set_flag :),
            "造孽啊........\n",
            }),
        ]) );
        set("chat_msg", ({
                (: cancel_give :),
                (: start_give :),
        }) );
        setup();
        carry_object("/obj/cloth")->wear();
}
 
void relay_say(object me, string str)
{
        if ((str == "必有妖孽")) {
                command("hehe");
                command("say 对呀.. 你就是妖孽... ");
                command("laugh "+(string)me->query("id"));
                return;
        }
}
 
void start_give()
{
        command("say 国之将亡.....");
}
 
void cancel_give()
{
        command("sigh");
}
 
void set_flag()
{
    object ob;
 
    if( !objectp(ob = query_temp("last_asker")) ) return;
    ob->set_temp("elder_info",1);
	return;
}
