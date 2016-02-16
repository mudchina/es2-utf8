// chuenyu.c

inherit NPC;

string kill_passenger(object who);

void create()
{
        set_name("淳于怀太", ({ "chunyu" }) );
        set("gender", "男性" );
        set("title", "淳于堡主");
        set("age", 47);
        set("str", 27);
        set("int", 12);
        set("per", 10);
        set("long", @LONG
淳于怀太是强盗出身，年轻时打家劫舍，无恶不做。尤于生
性恶顽，没人愿收其为徒。但他绝顶聪明，盗百家之长而集
于一身。
LONG
);
        set("attitude", "killer");


        set("combat_exp", 10000);
        set("bellicosity", 3000 );
        set("chat_chance", 50);
        set("chat_msg", ({
"淳于怀太喝道：呔！你竟敢坏大爷的好事！\n",
         }) );
        set_skill("unarmed", 60);
        set_skill("whip", 30);
        set_skill("dodge", 40);
        set_skill("parry", 30);
        set_skill("snowwhip", 80);
        set_skill("liuh-ken", 20);
        set_skill("pyrobat-steps", 100);
        map_skill("whip", "snowwhip");
        map_skill("unarmed","liuh-ken");
        map_skill("dodge", "pyrobat-steps");
        set("score", 100);

        setup();

        add_money("gold", 50); 
        carry_object(__DIR__"obj/chwhip")->wield();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
        message_vision("淳于怀太喝道：呔！你竟敢坏大爷的好事！\n",ob);
                kill_ob(ob);
        }
}

