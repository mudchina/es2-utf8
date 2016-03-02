// Mon  08-21-95
 
inherit NPC;
 
string ask_jade();
string ask_drug();
 
void create()
{
        seteuid(getuid());
        set_name("沈万年",({"shen wen-nien","shen"}));
        set("title","沈记商行掌柜");
        set("gender", "男性" );
        set("age",45);
        set("combat_exp",30);
        set("attitude", "friendly" );
        set_temp("apply/dodge",5);
        set_temp("apply/attack",3);
        set("inquiry", ([
        "玉佩" : (: ask_jade :),
        "蒙汗药" : (: ask_drug :),
        ]) );
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("silver",1);
}
 
void init()
{
        add_action("list_item","list");
        add_action("buy_item","buy");
}
 
int list_item()
{
        write("你看到:\n");
        write("柜子上一堆冥纸和香烛等, 标价 10 文钱. 墙上挂著几把竹扫帚,\n");
        write("每把 50 文钱. 柜台上摆\著一块木牌, 上面写著:\n");
        write("棺材: 时价. 没看到的东西问一下掌柜的.\n");
        return 1;
}
 
int buy_item(string str)
{
        command("shake");
        command("say 我不卖东西给陌生人!");
        return 1;
}
 
string ask_jade()
{
    if(this_player()->query_temp("drunk")) {
        command("whisper "+(string)this_player()->query("id")+
        " 这... 别宣扬出去, 这货很烫手, 给我十五两银子东西就是你的了.\n");
    }
    return "今天天气不错.... \n";
}
 
string ask_drug()
{
    if(this_player()->query_temp("drug")) {
        command("whisper "+(string)this_player()->query("id")+
        " 一两银子, 不要跟我讨价还价.\n");
    }
    return "嗯......\n";
}
 
int accept_object(object who, object ob)
{
    object item;
    if ((ob->value() == 1500) && (who->query_temp("drunk"))) {
    return 1;
    }
    if (ob->value() == 100) {
    item = new("/obj/slumber_drug");
    item->move(this_object());
    command("give drug to "+(string)who->query("id"));
    return 1;
    }
    return 0;
}
 
