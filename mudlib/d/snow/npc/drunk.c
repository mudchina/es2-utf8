inherit NPC;
 
void do_drink();
 
int has_alcohol;
 
void create()
{
        seteuid(getuid());
        set_name("醉汉", ({"drunk", "man", "drunk man"}));
        set("long", @TEXT
一个喝得醉醺醺的年轻人.....
TEXT
        );
        set("gender","男性");
        set("age",17);
        set("con",30);
        set("str",30);
        set("combat_exp",100);
        set("attitude","heroism");
        set("chat_chance",10);
        set("chat_msg", ({
        (: do_drink :), }) );
        setup();
        carry_object("/obj/cloth")->wear();
        carry_object("/obj/example/wineskin");
        has_alcohol = 1;
}
 
void do_drink()
{
    object *list, ob;
    int i, can_drink;
    if ((int)this_object()->query("water") >= 380) {
        command("sing");
        return;
    }
    list = all_inventory(this_object());
    i = sizeof(list);
    can_drink = 0;
    while (i--) {
        if ((string)list[i]->query("liquid/type") == "alcohol") {
            ob = list[i];
            can_drink = 1;
        }
    }
    if (can_drink) {
        command("drink "+(string)ob->query("id"));
        if ((int)ob->query("liquid/remaining") == 0)
            command("drop wineskin");
    }
    else {
        has_alcohol = 0;
        command("sigh");
        command("say 酒..... 给我酒....");
    }
    return;
}
 
int accept_object(object who, object ob)
{
    if ((string)ob->query("liquid/type")=="alcohol") {
        if ((int)ob->query("liquid/remaining") == 0) {
            command("shake");
            command("say 去去去去去.. 我又不是收破烂的...");
            return 0;
        }
        else {
            if ((int)ob->query("liquid/remaining") <= 5) {
                command("say 真没诚意, 剩么一点... ");
                return 0;
            }
            if (has_alcohol) {
                command("say 多谢, 不过我还有酒... ");
            }
            else {
                has_alcohol = 1;
                command("grin");
                if (who->query_temp("give_alcohol")) {
                    who->set_temp("know_drug",1);
                    command("whisper "+(string)who->query("id")+
                    " 听说沈记商行有在卖蒙汗药...\n");
                return 1;
                }
                if (who->query_temp("elder_info")) {
                    who->set_temp("give_alcohol",1);
                    command("whisper "+(string)who->query("id")+
                    " 嗯.. 你是想问我玉佩的事吧? 我卖给沈老板了, 那东西不吉祥...\n");
                } else {
                    command("say 多谢啦.....");
                    command("sing");
                }
                return 1;
            }
        }
    }
    else return 0;
}
 
