// Mon  08-21-95

inherit NPC;

void create()
{
        seteuid(getuid());
        set_name("妇人",({"woman"}));
        set("gender","女性");
        set("age",40);
        set("combat_exp",50);
        set_temp("apply/dodge",3);
        add_money("coin",100);
        set("chat_chance",7);
        set("chat_msg", ({
        "妇人说道：我说啊, 管管你们家那小鬼啊.\n",
        "妇人说道：明知山洞那边闹鬼, 没事带著我们家那两个跑过去.\n",
        "妇人打开锅盖\闻了一下.\n",
        "妇人朝门外看了看.\n",
        "妇人说道：村长家前几天遭小偷, 我看那个醉鬼有嫌疑喔...\n",
        }) );
        setup();
        carry_object("/obj/cloth")->wear();
}
