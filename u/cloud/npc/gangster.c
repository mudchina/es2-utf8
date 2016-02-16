// gangster.c

inherit NPC;

string kill_passenger(object who);

void create()
{
        set_name("卧龙岗强盗", ({ "gangster" }) );
        set("gender", "男性" );
        set("age", 27);
        set("str", 27);
        set("int", 12);
        set("per", 10);
        set("long", @LONG
这强盗满脸伤疤，虎背熊腰，一脸凶狠而霸道的样子。
LONG
);
        set("attitude", "heroism");

        set("combat_exp", 10000);

//        set("chat_chance", 1);
//        set("chat_msg", ({
//             "强盗喝道：呔！此山是我开，
//此树乃我栽。要想从此过，留下买路财！\n",
//              "强盗将你上上下下打量了一番，
//说道：识相的放下十两买路钱走你的路。\n",
//        }) );

        set("inquiry", ([
                "买路钱": 
"看你也不象有钱的样子，大爷我只要十两金子意思一下。\n",
        ]) );

//        set("chat_chance_combat", 1);
//        set("chat_msg_combat", ({
//              "强盗显是以劫为生，刀刀冲要害而来。\n",
//              "强盗高喊：叫你人财两空。\n",
//        }) );

        set_skill("unarmed", 100);
        set_skill("blade", 40);
        set_skill("dodge", 40);
        set_skill("parry", 50);

        set("score", 100);

        setup();

        add_money("gold", 1); 
        carry_object("/u/cloud/obj/npc/gangster/blade")->wield();
        carry_object("/obj/dust");
        carry_object("/obj/example/dart")->wield();
        carry_object("/obj/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob->query("marks/强盗") ) {
                set("chat_chance", 1);
                set("chat_msg", ({
                        
"强盗喝道：呔！此山是我开，此树乃我栽。要想从此过，留下 
买路财！\n",
                        
"强盗将你上上下下打量了一番，说道：识相的放下十两买路钱 
走你的路。\n",
                }) );
                kill_passenger(ob);
        }
}

int accept_object(object who, object ob)
{
        if( !who->query("marks/强盗") ) {
                if( ob->value() >= 100000 ) {
                        say("强盗接过钱，眼睛瞪得大大的，点了点头，说道：
大爷今天做个善人，放你条生路。还不快滚！\n");
                        who->set("marks/强盗", 1);
                        return 1;
                } else {
                        say("强盗往地上吐了口唾沫，目露凶光，说道：
不给你点颜色你是不知道大爷的厉害！\n");
                        kill_passenger(who);
                        return 0;
                }
        } else
                
say("强盗眼中放出异样的光彩，忙不迭的笑道：算你识相，以后我不会
难为你的。\n");
        return 1;
}

string kill_passenger(object who)
{
//        set("pursuer", 1);
        set("attitude", "aggressive");
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "强盗显是以劫为生，刀刀冲要害而来。\n",
                "强盗高喊：叫你人财两空。\n",
        }) );
        kill_ob(who);
        return 0;
}

int accept_fight(object me)
{
        command("say 竟敢太岁爷头上动土？纳命来！");
        command("grin");
        kill_passenger(me);
        return 1;
}

 
