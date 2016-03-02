//judge_man.c

#include <ansi.h>
#define THIEF 3
#define ROBBER 5
inherit NPC;

void settle_lawsuit(object);
void test_crime( );
int do_charge(string);

static int in_test=0;

void create()
{
        set_name("程不平", ({ "county magistrate","magistrate" }) );
        set("title", "乔阴县县官");
        set("gender", "男性" );
        set("age", 22);

        set("str", 22);
        set("cor", 25);
        set("cps", 20);
        set("int", 30);
        set("per", 23);
        set("con", 24);
        set("spi", 15);
        set("kar", 25);

        set("long",

"他虽然出身望族，然攻读刻苦，榜中探花，如今已是才高八斗，满腹\n"
"经纶，还略通佛理。为官数年清贫廉正，人人敬仰。\n"
);
        set("combat_exp", 5000000);
        set("attitude", "friendly");
        set("env/wimpy", 30);

        set("max_atman", 1000);
        set("atman", 1000);     set("atman_factor", 3);
        set("max_force", 1000);
        set("force", 1000);     set("force_factor", 100);
        set("max_mana", 1000);
        set("mana", 1000);      set("mana_factor", 3);

        set_skill("buddhism",90);
        set_skill("unarmed", 100);
        set_skill("literate",100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("pyrobat-steps",100);
        set_skill("force", 100);
        set_skill("spells", 100);

        map_skill("dodge","pyrobat-steps");

        set("chat_chance",90);
        set("chat_msg",({
                        (: test_crime :),
                        }));
        setup();

        add_money("gold", 100);
        add_money("silver",100);
}

init()
{
add_action("do_charge","charge");
}

int accept_fight(object me)
{
        command("scowl");
        command("say 这是衙门，快回去吧。");
        return 0;
}

int settle_lawsuit(object crime)
{
int level,i;
int gin,kee,sen,condition;
if (level=crime->query("crime_lv"))
        {
message_vision(HIR"来人哪！把$N拖下去打"+chinese_number(level*10)
                                +"大板！\n",crime);
        gin=10-crime->query("max_atman")/100;
        kee=10-crime->query("max_force")/100;
        sen=10-crime->query("max_mana")/100;
        if (gin<0) gin=0;
        if (kee<0) kee=0;
        if (sen<0) sen=0;
        for (i=1;i<=level;i++)
                {
        condition=0;
                if (crime->query("eff_gin")<gin)
                        {
                        crime->set("eff_gin",1);
                        crime->set("gin",1);
                        condition++;
                        }
                crime->receive_damage("gin",gin);
                crime->receive_wound("gin",gin);
                if (crime->query("eff_kee")<kee)
                        {
                        crime->set("eff_kee",1);
                        crime->set("kee",1);
                        condition++;
                        }
                crime->receive_damage("kee",kee);
                crime->receive_wound("kee",kee);
                if (crime->query("eff_sen")<sen)
                        {
                        crime->set("eff_sen",1);
                        crime->set("sen",1);
                        condition++;
                        }
                crime->receive_damage("sen",sen);
                crime->receive_wound("sen",sen);
                if (condition==3)
                        {
                        message_vision(HIR "哎, 早知今日,何必当初?\n" NOR+
                        "来人呀, 把$N给我抬出去!\n"+
                        "...退...堂...!\n",crime);
                        crime->unconcious();
                        crime->add("crime_lv",-1);
                        }
                message_vision(HIR "$N对$n说道: 再敢犯案, 定斩不饶!\n" NOR,this_object(),crime); 
                }
        crime->move(find_object("/d/choyin/court1.c"));
        if (!crime->query("crime_lv"))
                crime->delete("crime_lv");
        }
else
        {
        tell_object(crime,"真是对不起, 下人办事不周, 让您受委屈了.\n");
        call_out((:call_other,crime,"move",find_object("/d/choyin/court1.c"):),1);
        }
 return 1;
}

void test_crime( )
{
object *players,bk;
int i;
if (in_test) return;
in_test=1;
players=users();
i=sizeof(players);
while(i--)
        {
        if((players[i]->query("crime_lv")
        ||players[i]->query("marks/强盗")
        ||players[i]->query("thief"))
        &&!players[i]->query("being_caught"))
                {
        tell_object(players[i],""+players[i]->query("being_caught"));
                seteuid(getuid());
              bk=new(__DIR__"yamen_po.c");
                bk->set("CatchWho",players[i]);
                bk->set("status","catching");
                bk->catchyou(players[i]);
                break;
                }
        }
in_test=0;
return;
}


int do_charge(string arg)
{
//charge sb. with steal, kill, MKS, PKS, bellecosity, crime
string who,why;
int permit;
object police,crimer;
if (!arg) return 0;
if (sscanf(arg,"%s with %s",who,why)!=2)
        return notify_fail("正确用法是: charge sb. with <reason>\n");
crimer=find_player(who);
if (!crimer)
                return notify_fail("对不起，你要告的人不在线上！\n");
switch (why)
        {
        case "steal":
                if (crimer->query("thief"))
                        {
                        if (crimer->query("thief")==1)
                                        crimer->delete("thief");
                        else    crimer->add("thief",-1);
                        crimer->add("crimer_lv",3);
                        permit=1;
                        }
                else permit=0;
                break;
        case "kill":
                if (crimer->query("marks/强盗"))
                        {
                        if (crimer->query("marks/强盗")==1)
                                                crimer->delete("marks/强盗");
                        else            crimer->add("marks/强盗",-1);
                        crimer->add("crimer_lv",5);
                        permit=1;
                        }
                else permit=0;
                break;
        case "MKS":
                if ((crimer->query("MKS")-crimer->query("combat_exp")/20)>random
(800)+800)
                        {
                        crimer->add("crime_lv",3);
                        crimer->add("MKS",-100);
                        permit=1;
                        }
                else permit=0;
                break;
        case "PKS":
                 if (random(crimer->query("PKS")))
                        {
                        crimer->add("crime_lv",8);
                        crimer->add("PKS",-1);
                        permit=1;
                        }
                else permit=0;
                break;
        case "杀气":
                if
(random(crimer->query("bellicosity"))>random(800)+800)
                        {
                        if (crimer->query("class")=="fighter"
                                &&random(crimer->query("bellicosity"))<1000)
                                {
                                permit=0;break;
                                }
                        crimer->add("crime_lv",2);
                        crimer->add("bellicosity",-200);
                        permit=1;
                        }
                else permit=0;
                break;
        case "crime":
                if (crimer->query("crime_lv"))
                        permit=1;
                else permit=0;
                break;
        default:
                return notify_fail("对不起，此类案件本县不受理。\n");
        }
if (permit) {say("hdjdjhjfdhsjfhjdshjfhdsjhfjsdhfj");}
         else {say("haha");}
if (permit)
        {
        seteuid(getuid());
        police=new("/d/choyin/npc/yamen_po.c");
        police->set("status","catching");
        police->set("CatchWho",crimer);
        if (environment(crimer)==find_object("/d/choyin/court1.c")
                ||environment(crimer)==find_object("/d/choyin/n_gate.c"))
                        crimer->move(find_object("/d/choyin/court1.c"));
        police->move(environment(crimer));
        say("嗯......的确如此!\n好吧, 我派人去抓"+
                        (crimer->query("gender")=="女性"?"她":"他")+
                        "来.\n");
        if (objectp(police=present("magistrate waiter",environment())))
        police->delete_temp("pending/beat");
crimer->move("/d/choyin/yamen");
call_out("settle_lawsuit",1,crimer);
        return 1;
        }
else
        {
        add("bad_man/"+who,1);
        if (query("bad_man/"+who)>3)
                {
                this_player()->add("crime_lv",2);
                tell_object(this_player(),"你竟敢诬告？！\n");
                call_out("settle_lawsuit",1,this_player());
                }
        return 1;
        }
}
