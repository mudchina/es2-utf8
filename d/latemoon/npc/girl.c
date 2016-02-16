inherit NPC;
 string show_dance();
string show_dragon();
 
void create()
{
        set_name("昭仪", ({ "zauyi", "joe" }) );
        set("title", "晚月庄第三代弟子");
        set("gender", "女性" );
        set("age",17);
        set("long", @TEXT
她看起来非常可爱。身材玲珑有致，曲线苗条。
第一眼印象，你觉的她舞蹈一定跳的不错，看她的一举一动
有一种说不出的流畅优雅！
TEXT
);
       set("class", "dancer");
        set("combat_exp", 4000);
        set("kee",270);
        set("san",100);
        set_skill("unarmed",20);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("blade",10);
         set_skill("spring-blade",7);
        map_skill("blade", "spring-blade");
        set_skill("force",50);
        set("force",450);
       set("max_force",450);
        set("force_factor", 2);
        set_temp("apply/armor", 30);
        set("inquiry", ([
         "图" : "这是一张非常真贵的湘绣舞曲图，我也在研究中。\n",
         "沧海龙吟" : "嗯 ...为这舞曲名。似乎雨梅姊知道。\n",
         "有凤来仪" : "嗯 ...为这舞曲名。(dancing yu-fong)很有名！ \n",
         "西出阳关" : "「幻影式舞步」步法与地点都很重要。\n",
         "芳绫" : "她聪明伶俐，会跳一些自创的舞步。\n",
         "画" : "沧海龙吟是一幅湘绣舞曲图，记载一些珍贵舞步。\n",
            "寒谷龙舞" : (: this_object(), "show_dance" :),
            "舞" : (: this_object(), "show_dragon" :)
        ]));
        setup();
        set("chat_chance", 8);
        set("chat_msg", ({
"昭仪以轻妙的舞步，在房内跳了起来!你看的入神。\n",
"昭仪抬头望著那幅图画，略有所思... \n"
        }) );
      carry_object(__DIR__"obj/yu_blade")->wield();
      carry_object(__DIR__"obj/flower_boot")->wear();
}

string show_dance()
{
        object me;
        string str;
        str = (string)this_object()->query("name");
        me = this_player();
        tell_object(me, str+"很奇怪的望著你，说道:嘻!你对舞有兴趣呀! \n");
        tell_object(me,"只见两眼溜来溜去，一种很神秘的表情，嘟著嘴。\n");
        tell_object(me,"过了一会说：好吧!偷偷跟你说，你可以查看墙上"
     +"的图。(dragon-dance) \n");
        return "....\n";
}
string show_dragon()
{
      object me;
      string str;
      str = (string)this_object()->query("name");
      me = this_player();
      tell_object(me, str+"很高兴的看著你，说道:嘻!你对舞有兴趣呀!\n");
      tell_object(me,"这有一幅图画，我从那悟到好多新舞步哦! \n");
      tell_object(me,"『 沧海龙吟』是一首失传以久的舞曲。传说....\n");
      return "......\n";
}

