// yamen_police.c
#include <ansi.h>
#define THIEF 3
#define ROBBER 5
#define GO 0
#define BACK 1

inherit NPC;

void patrol();
void catchyou(object);
int mygo(string);
int do_go(string arg);
int do_quit(string arg);
int accept_bribery(string);

int direction=GO;

mapping BigWay=([
                "/d/choyin/court1":({"south",0}),
                "/d/choyin/crossroad":({"east","north"}),
                "/d/choyin/s_street5":({"east","west"}),
                "/d/choyin/s_street4":({"east","west"}),
                "/d/choyin/s_street1":({"north","west"}),
                "/d/choyin/s_street2":({"north","south"}),
                "/d/choyin/tree_tomb":({"north","south"}),
                "/d/choyin/n_street3":({"north","south"}),
                "/d/choyin/n_street2":({"north","south"}),
                "/d/choyin/n_street1":({"north","south"}),
                "/d/choyin/n_gate":({"west","south"}),
                "/u/cloud/sunhill/road1":({"north","east"}),
                "/d/snow/sroad3":({"north","east"}),
                "/d/snow/sroad4":({"north","south"}),
                "/d/waterfog/sroad1": ({0,"south"}),
                ]);

void create() {
        string *surname=({"慕容","西门","公孙","上官","南宫","欧阳","司徒",});
     set_name(surname[random(sizeof(surname))]+"巡捕", ({ "yamen police","yamen"
,"police"}) );
     set("gender", "男性" );
     set("age", 25);
     set("str", 45);
     set("cor", 50);
     set("cps", 35);
     set("int", 20);
     set("per", 20);
     set("kar", 15);
     set("long",@LONG
     巡捕个个身手矫健，强盗、山贼无不闻风丧胆。
LONG
);
     set("status","patrol");
     set("CatchWho",0);
     set("combat_exp", 500000);
     set("attitude", "heroism");
     set("chat_chance_combat", 40);
     set("chat_msg_combat", ({
                            "巡捕说道：你想干什么? 还不跟我去县衙受审!?\n",
                            "巡捕说道：大胆! 居然敢当街拒捕! 想造反？\n",
                            "巡捕手中的刀越砍越快，让你应接不暇。\n",
                            "巡捕说道：别胡闹了，还是乖乖的跟我走吧。\n"
                            }) );
     set ("inquiry",([
                "bribery":
"说哪里话来，县太爷清贫廉正，我们作手下的岂能辱没他的名声？\n"+
"收起你的钱吧！\n",
                "salary":
"哎，老爷俸银微薄，我们的年饷自然更少了......\n",
                "money":
"说实在的，我也想要钱。但要是让老爷知道了我收受贿赂(bribery)，\n不死也得扒层皮\n
",
                        ]));
     set ("chat_chance",99);
     set ("chat_msg", ({
                      (:call_out,"patrol",0:),
                      }) );
         set("pursuer",1);
     set_skill("blade", 100);
     set_skill("parry", 90);
     set_skill("dodge", 70);
     set_skill("perception",50);
     set_skill("pyrobat-steps",60);
     set_skill("spring-blade", 100);
     map_skill("blade", "spring-blade");
     map_skill("dodge", "pyrobat-steps");
     setup();
     direction=GO;
     carry_object(__DIR__"obj/blade")->wield();
     carry_object(__DIR__"obj/cloth")->wear();
     carry_object(__DIR__"obj/amulet");
     add_money("silver",30);
}

void init()
{
object catchwho,you,*npc;
object oldman,start_room;
int i,tmp;
catchwho=query("CatchWho");
you=this_player();
if (query("status")=="patrol")
   {
   if (!is_fighting()&&interactive(you)&&living(you))
      {
        npc=all_inventory(environment());
        i=sizeof(npc);
        while (i--) {
                if (npc[i]->query("id")=="gangster"&&!userp(npc[i]))
                        {
                        say(HIW "今儿是什么日子？\n"+"居然"+
                                npc[i]->query("name")+
                               "也敢在大街上溜哒！" NOR);
                        npc[i]->remove_all_enemy();
                        say("去死吧！！\n");
                        EMOTE_D->do_emote( npc[i],"fear");
                        kill_ob(npc[i]);
                        npc[i]->kill_ob(this_object());
                        }
                else if (npc[i]->query("title")=="野羊山寨三寨主"&&!userp(npc[i]
))
                        {
                        say(HIR "哼，手下败将！总有一天我们要荡平野羊山�
n" NOR);
                        npc[i]->remove_all_enemy();
                        EMOTE_D->do_emote( npc[i],"fear");
                        kill_ob(npc[i]);
                        }
                }
        if (you->query("thief")&&random(10)<7)
           {
           say (HIR "闹了半天原来"+you->query("name")+
                        "是个贼啊! 我走一趟吧!\n" NOR);
           you->add("crime_lv",THIEF);
           you->add("thief",-1);
           if (!you->query("thief")) you->delete("thief");
           catchyou(you);
                return;
           }
        else
            if (you->query("marks/强盗")&&random(10)<9)
               {
               message_vision("$N对着$n喝道：光天化日之下，你居然也敢行凶杀人？�
共挥胛一厝コ园遄樱n"
                +"说罢，$N解下铁链套在$n的脖子上。\n",this_object(),you);
                        you->add("crime_lv",ROBBER);
                        you->add("marks/强盗",-1);
                        if (!you->query("marks/强盗")) you->delete("marks/强盗")
;
                catchyou(you);
                }
        }
   }
else if (query("status")=="catching")
   {
   catchyou(catchwho);
   message_vision(HIR "只见$N突然从腰间解下一条铁链套在$n的脖子上。\n"NOR,
                this_object(),catchwho);
   }
else {
      if (objectp(catchwho=this_object()->query("CatchWho")))
        {
            if (BigWay[file_name(environment())][direction]==0)
                        {
        say("try to patrol\n");
                        start_room=find_object("/d/choyin/yamen.c");
                        oldman=find_object("/d/choyin/npc/judgeman.c");
                        oldman=present(oldman->query("id"),start_room);
                        write(oldman->query("id"));
                        catchwho->move(start_room);
                        move(start_room);
                        say("老爷，人犯已带到，小人巡街去了。\n");
                        set("CatchWho",0);
                        direction=GO;
                        set("status","patrol");
                        move(find_object(query("startroom")+".c"));
                        patrol();
                        call_other(oldman,(:call_out,"settle_lawsuit",catchwho,2
:));
                        return;
                        }
                }
        }
add_action("do_go","go");
add_action("do_quit","quit");
add_action("accept_bribery","bribe");
}

void patrol()
{
int i,on_way;
object *content,catchwho,start_room,crime,oldman;
string *bigwayname,where,dir;
bigwayname=keys(BigWay);
where=file_name(environment());
write("in patrol\n");
for (i=0;i<sizeof(bigwayname);i++)
    {
    if (where==bigwayname[i])
       {
       on_way=1;
       break;
       }
    else on_way=0;
    }
if (on_way)
   {
   if (this_object()->query("status")=="patrol")
      {
      if (!BigWay[where][direction]) direction=1-direction;
      }
   else if (this_object()->query("status")=="catching")
      {
      catchyou(catchwho);
      message_vision(HIR "只见$N突然从腰间解下一条铁链套在$n的脖子上"NOR,
                        this_object(),catchwho);
      }
   else
      {
        write("here???\n");
         }
  }
else
   {
   content=all_inventory(this_object());
   for (i=0;i<sizeof(content);i++)
       {
       if (content[i]->query("id")=="amulet")
                {
                if (!stringp(dir=content[i]->query("map")[where]))
                        {
                        move(start_room=find_object(query("startroom")+".c"));
                        if (objectp(crime=query("CatchWho")))
                                {
                                if (where==file_name(environment(crime)))
                                        crime->move(start_room);
                                }
                        }
                else mygo(dir);
          break;
          }
  }
return;
}
mygo(BigWay[where][direction]);
}

void catchyou(object crime)
{
object ob;
ob=this_object();
while (environment(ob)!=environment(crime))
                   move(environment(crime));
crime->set_leader(ob);
set("CatchWho",crime);
set("status","caught");
crime->set("being_caught",1);
direction=BACK;
return;
}

int mygo(string dir)
{
//GO_CMD->main(this_object(),dir);
command("go "+dir);
return 1;
}

int do_go(string arg)
{
object me;
me=this_player();
if (!me->query("being_caught")) return 0;
tell_object(me, "嘿嘿, 还想往哪逃?!\n");
return 1;
}

int do_quit(string arg)
{
object me;
me=this_player();
if (!me->query("being_caught")) return 0;
if (is_fighting()&&random(20)<16)
        {
        me->delete("being_caught");
        set("status","patrol");
        return 0;
        }
message_vision(HIR "$N紧紧拎着$n的衣领, $n无法退出!\n" NOR, this_object(),me);
return 1;
}

void die()
{
object killer,ob,room;
string file;
int i;
if (objectp(killer=query_temp("last_damage_from")))
        {
        room=find_object(query("startroom"));
        killer->delete("being_caught");
        killer->add("crime_lv",5);
/*      for (i=0;i<2;i++)
                {
                seteuid(getuid());
                ob=new("/d/choyin/npc/yamen_po.c");
                ob->set("call_out",1);
                ob->set("CatchWho",killer);
                ob->set("persuer",1);
                ob->set("startroom",query("startroom"));
                ob->move(environment());
                message_vision(HIR "大胆狂徒，$N...居然敢杀戮公差$n！休走，看刀�
n" NOR,killer,this_object());
                ob->kill_ob(killer);
                if (stringp(file=find_command("kill")))
                        {
                        message_vision(file+"$N$n",killer,ob);
                        call_other(file,"main",killer,ob->query("id"));
                        }
                }
*/
        }
::die();
}

int accept_bribery(string arg)
{
object money_ob,me,ob;
string toid,money;
int amount,bv1,i;
me=this_player();
if(!(me->query("being_caught"))) return 0;
if (!arg||sscanf(arg,"%s with %d %s",toid,amount,money)!=3) return 0;
if (!objectp(present(toid,environment())))
        return notify_fail("你要贿赂谁？\n");
money_ob=present(money+"_money",this_player());
if (!money_ob) return notify_fail("你身上没有这种货币。\n");
if( amount < 1 ) return notify_fail("货币使用至少要一个/每次。\n");
if( (int)money_ob->query_amount() < amount )
                return notify_fail("你身上没有那多" + money_ob->query("name") +
"。\n");
bv1 = money_ob->query("base_value");
if( !bv1 ) return notify_fail("这种东西不值钱。\n");
if (bv1*amount>=100000)
        {
        write("这怎么好?......要是让老爷知道了......\n");
        write("盛情难却....我就收下了..\n");
        EMOTE_D->do_emote(this_object(),"grin",me->query("id"));
        ob=new(base_name(money_ob));
        ob->move(this_object());
        ob->set_amount(amount);
        money_ob->add_amount(-amount);
        me->delete("being_caught");
        if (me->query("crime_lv")>3)
                        me->add("crime_lv",-3);
        else me->delete("crime_lv");
        me->set_leader(0);
        set("status","patrol");
        set("CatchWho",0);
        direction=GO;
        return_home(find_object(query("startroom")));
        }
else
        {
        write("你这是什么意思?......谁稀罕你的钱?!\n");
        me->add("crime_lv",1);
        }
return 1;
}

