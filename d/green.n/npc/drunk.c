// Mon  08-21-95
 
inherit NPC;
 
void do_drink();
string about_jade();
 
void create()
{
        seteuid(getuid());
        set_name("醉汉", ({"drunk", "man", "drunk man"}));
        set("long", @TEXT
TEXT
        );
        set("gender","男性");
        set("age",37);
        set("con",30);
        set("str",30);
        set("combat_exp",332);
        set("attitude","heroism");
        set("chat_chance",10);
        set("chat_msg", ({
        (: random_move :),
        (: do_drink :), }) );
        set("inquiry", ([
        "玉佩" : (: about_jade :),
        ]) );
setup();
        carry_object("/obj/cloth")->wear();
        carry_object("/obj/example/wineskin");
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
            command("drop "+(string)ob->query("id"));
    }
    else {
        command("sigh");
        command("say 酒........");
    }
    return;
}
 
int accept_object(object who, object ob)
{
    if ((string)ob->query("liquid/type")=="alcohol") {
        if ((int)ob->query("liquid/remaining") == 0) {
            command("shake");
            command("say 不要拿空瓶子来骗我!");
            return 0;
        }
        else {
            command("nod");
            command("say 多... 多谢!");
            who->set_temp("given_drink",1);
            return 1;
        }
    }
    else return 0;
}
 
string about_jade()
{
    object ob;
    ob = this_player();
    if (ob->query_temp("given_drink")) {
        if (ob->query_temp("asked_jade")) {
            command("whisper "+(string)ob->query("id")+
            " 那个姓沈的, 有时会收一些来路不明的东西.. ");
            this_player()->set_temp("drunk",1);
            return "嗯... \n";
        }
        else {
            command("? "+(string)ob->query("id"));
            return "你在说什么?\n";
        }
    }
    else {
        command("? "+(string)ob->query("id"));
        return "你... 是那根.... 葱...?\n";
    }
}
 
