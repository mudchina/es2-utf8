inherit NPC;
 
void create()
{
        set_name("芳绫",  ({ "funlin","fun","lin" }) );
        set("gender", "女性" );
        set("age",18);
        set("long", @TEXT
她看起来像个小灵精，头上梳两个小包包头。
她坐在地上，看到你看她便向你作了个鬼脸!
你想她一定是调皮才会在这受罚!
TEXT
);
       set("class", "dancer");
       set("combat_exp", 2000);
        set_skill("unarmed", 20);
        set_skill("whip", 20);
        set_skill("dodge", 20);
        set_skill("move", 30);
        set_skill("stormdance", 20);
        map_skill("dodge","stormdance");
        set_skill("dodge", 30);
        set_skill("force", 15);
        set("force", 500);
        set("max_force", 300);
        set("force_factor", 2);
        set_temp("apply/armor", 30);

         set("chat_chance", 7);
       set("chat_msg", ({
"顽皮的芳绫向你扮个鬼脸。  *^G^* \n",
"芳绫走到中央，一个姿势(Pose)。哇!你没想到她跳舞时竟有此深造诣。\n",
"芳绫说：好不好看！这可是我花好久练成的哦! \n",
"芳绫缓缓的移动著，手上的动作变化万千，有一种说不出的美妙。\n",
"芳绫说：你好烦哦! 快走开! \n",
"芳绫说：你想学可以去问昭仪姐，她会的比我多。嘻! \n",
"芳绫说：丑八怪! 不要烦我。走开啦! \n",
"她嘟著嘴。有点生气的翻过头去，不理你！\n"
       }) );
       create_family("晚月庄",5,"弟子");
        setup();
        carry_object(__DIR__"obj/whip")->wield();
        carry_object(__DIR__"obj/deer_boot")->wear();
        carry_object(__DIR__"obj/skirt5")->wear();
}

int accept_object(object who, object ob)
{
     object me;
     string objname;

     me = this_player();
     objname = (string)ob->name();

        if ( objname != "竹蜻蜓")  {
           command("smile");
            say ("这要送给我啊?! 怎么好意思!谢谢你。\n");
           command("blush");
             return 1;
            }
        if( !who->query_temp("moon/竹蜻蜓") )  {

            tell_object(me, "芳绫很开心的拿起竹蜻蜓把玩!\n\n");
            tell_object(me, "满怀感激的谢谢你! 她小声的在你耳边说：\n");
            tell_object(me, "『 庄内前厅某处藏有一宝物手镯哦!』\n");
            tell_object(me, "你可以找找看! (search bracelet) \n");
            who->set_temp("moon/问题二", 1);
            who->set_temp("moon/竹蜻蜓", 1);
         } else {
             say ("谢谢!我已经告诉你秘密了呀!去找呀! \n");
             return 1;
          }
          return 1;
}
