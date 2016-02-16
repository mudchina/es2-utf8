// magistrate_waiter.c

#include <command.h>
inherit NPC;

int do_nod(string);
void remove_effect(object);
void go_in();
void greeting(object);

void create()
{
        set_name("带刀侍卫", ({ "magistrate waiter","waiter" }) );
        set("gender", "男性" );
        set("age", 44);
        set("str", 45);
        set("cor", 28);
        set("cps", 18);
        set("int", 10);
        set("per", 10);
        set("long", @LONG
带刀侍卫皆为槐阳王程老王爷麾下骁将,身负绝艺.
LONG
);
        set("combat_exp", 1000000);
        set("attitude", "heroism");
        set_skill("blade",120); 
        set_skill("parry", 80);
        set_skill("dodge", 120);
        set_skill("fall-steps",120);
        set_skill("shortsong-blade",150);
        map_skill("blade","shortsong-blade");  
        map_skill("dodge","fall-steps");  
        set("pending/charge",0);
        setup();
        add_money("silver",40);
        carry_object(__DIR__"obj/blade")->wield(); 
        carry_object("/obj/cloth")->wear();        
}

void greeting(object who)
{
return_home(find_object("/d/choyin/yamen.c"));
command("open door");
command("go south");           //这些走法与路径有关
command("go south");
if (!find_player(who->query("id"))||environment()!=environment(who))
        {
                say("奇怪，刚才是谁啊？\n");
                go_in();
        }
who->delete_temp("have_beat_drum");
add("pending/charge",1);
if (query("pending/charge")>20)
        {
        say("老爷今天太累了，请明天再来吧。\n");
        call_out("go_in",10);
        return;
        }
message_vision("$N从衙门内院走了出来，看了看$n，说道：是你击鼓申冤吗？(yes/no)\n
",this_object(),who);
set_temp("pending/beat",who);
add_action("do_nod",({"yes","no"}));
call_out("remove_effect",who->query("score")/100+10,who->query("id"));
}

int do_nod(string arg)
{
object who,waiter;
who=this_player();
waiter=this_object();
if (who!=query_temp("pending/beat"))
        return notify_fail("没说你呢！捣什么乱！去去去...一边呆着！\n" );
remove_call_out("remove_effect");
if (query_verb()=="no")
        {
        write(waiter->query("name")+"双眼一瞪，喝道：没冤情你击什么鼓？！\n");
        COMBAT_D->do_attack(this_object(),who);
        write("一边凉快凉快.\n");
        COMBAT_D->do_attack(this_object(),who);
        who->move(find_object("/d/choyin/yamen_yard.c"));
        delete_temp("pending/beat");
        go_in();
        return 1;
        }
else
        {
        who->set_leader(waiter);
        command("hmm");
        say("好吧，跟我来....\n");
        GO_CMD->main(this_object(),"east");
        command("close door");
        call_out("greeting2",3,who);
        return 1;
        }
}

void remove_effect(string quire)
{
if (file_name(environment())!="/d/choyin/court1")
        return;
if (objectp(find_player(quire))&&environment()==environment(find_player(quire)))
        {
        say(RANK_D->query_self_rude(this_object())+"没功夫和你罗嗦！！\n");
        delete_temp("pending/beat");
        go_in();
        }
return;
}

void go_in()
{
        move(find_object("/d/choyin/yamen_yard.c"));
        command("close door");
        return_home(find_object("/d/choyin/yamen.c"));
        return;
}

void greeting2(object who)
{
        write(this_object()->query("name")+"高声说道, 老爷......我把击鼓人带上来
了！.....\n");
        say("老爷就在堂上，这边走......\n");
        command("go north");
        who->set_leader(0);
        tell_object(who,"到了，......有冤就申(charge)吧。\n");
}
