// Mon  08-21-95

inherit NPC;

void do_sigh();
string about_jade();
void do_say_one();
void do_say_two();
string about_theft();
 
void create()
{
        seteuid(getuid());
        set_name("村长", ({"elder", "oldman", "man"}));
        set("long", @TEXT
在你面前的是一个满脸愁容的老人.
TEXT
        );
        set("gender","男性");
        set("age",95);
        set("combat_exp",500);
        set("attitude","friendly");
        set("chat_chance",10);
        set("inquiry", ([
        "玉佩" : (: about_jade :),
        "遭小偷" : (: about_theft :),
        ]) );
        set("chat_msg", ({
        (: do_sigh :),
        (: do_say_two :),
        (: do_say_one :) }) );
        setup();
        carry_object("/obj/cloth")->wear();
}

void do_say()
{
    command("sigh");
    return;
}

void do_say_one()
{
    command("say 人心不古.... ");
    command("sigh elder");
    return;
}

void do_say_two()
{
    command("say 玉佩不见了.... ");
    command("sigh elder");
    return;
}

string about_jade()
{
    command("sigh");
    command("say 别提了... 前几天遭小偷, 别的不拿就拿这个.");
    command("hmm");
    return "希望不要被有心之人滥用.";
}

string about_theft()
{
    this_player()->set_temp("asked_theft",1);
    command("sigh");
    command("say 造孽啊.... ");
    command("say 青石村从来没有发生过窃案, 曾几何时... ");
    command("sigh");
    return "最近村里来了些陌生人, 不知道跟他们有没有关系...";
}

