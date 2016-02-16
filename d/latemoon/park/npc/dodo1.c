inherit NPC;

void create()
{
        set_name("小金鼠", ({ "dodo" }) );
        set("race", "野兽");
        set("age", 1);
        set("long", "一只可爱的长尾巴的小金鼠。 \n");

        set("str", 20);
        set("cor", 17);

         set("combat_exp", 1000);
        set("score", 10);
        set("dodge",20);

        set("attitude","friendly");

        set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
         set("verbs", ({ "bite" ,"claw" }) );
        set_temp("armor", 10);

    set("chat_chance", 15);
    set("chat_msg", ({
            (: this_object(), "random_move" :),
"小金鼠摇摇尾巴!全身晃呀晃! \n",
"小金鼠眼睛眨呀眨!好像快睡著了! \n",
"嘟嘟玩太累了!睡著了! \n",
"小金鼠「嘟嘟」它跳啊跳的! \n",
"小金鼠「嘟嘟」眼睛眨呀眨看著你 \n",
"小金鼠发出「  叽! 叽!」」的叫声! \n"
    }) );

        setup();
}
