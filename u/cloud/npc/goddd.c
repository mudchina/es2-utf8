inherit NPC;	
#include <ansi.h>	
int time_period(int timep, object me);		

void create()	
{
        set_name("朱鸿雪", ({ "Zhu hongxue", "zhu hongxue", "zhu" }) );	

        set("gender", "女性");	        
	set("age", 69);
        set("long",
               "朱鸿雪慈眉善目，可又有谁能想到她竟是杀手组织中人。\n");	
        set("attitude", "peaceful");	
        set("skill_public",1);	
        set("str", 26000);	
        set("cor", 30);	
        set("int", 24);	        
	set("cps", 30);	

        set("force", 40000);	
        set("max_force", 80000);	
        set("force_factor", 1000);	

        set("combat_exp", 1000000);	
        set("score", 200000);	

        set_skill("unarmed",100);	
        set_skill("dodge", 100);	
        set_skill("force", 100);	    
	set_skill("pyrobat-steps", 100);	

        set_skill("snowshade-force", 100);	
        set_skill("snowshade-sword", 100);	
        set_skill("sword", 100);	
        map_skill("sword","snowshade-sword");	
        map_skill("force","snowshade-force");	
        map_skill("dodge","pyrobat-steps");	
        set("force", 5000);	
        set("max_force", 5000);	
        set("force_factor", 10);	

        create_family("东方神教", 2, "教主");	

        setup();	

        carry_object("/d/latemoon/obj/deer_boot")->wear();	
        carry_object("/d/latemoon/obj/sword")->wield();	
}	

int accept_fight(object me)	
{
        command("say 生命可贵！不要自寻死路！");	
        return 0;	
}

void init ()
{
        add_action("give_quest", "quest");	
}

int give_quest () 
{
        mapping quest ;	
        object me;	
        int j, combatexp, timep,factor,num,tfinished;	
        string tag = "1000000";	
	string *levels = ({	
		"1000",
		"1500",
		"2000",
		"3000",
		"5000",
		"8000",
		"10000",
		"13000",
		"17000",
		"22000",
		"40000",
		"50000",
		"60000",
		"80000",
		"100000",
		"200000",
		"400000",
		"800000",
		"1000000"
	});

        me = this_player();	
// Let's see if this player still carries an un-expired task	
        if ((int)me->query("combat_exp") <= 1000) {	
		message_vision("朱鸿雪奇怪的眼神盯着$N,说:" 就凭你这种小角色也想来这？\n");
		message_vision("还不快滚!\n");	
	        return 0;	
		}
       if((quest =  me->query("quest"))) {	
       		if( ((int) me->query("task_time")) >  time() )	
                	return 0;	
	    else {	
                message_vision("朱鸿雪向$N一甩袍袖，说道：真没用！不过看在你还回来见老夫的份上，就在给你一次机会．\n", me);		
                me->set("kee", me->query("kee")/2+1);	
		}
		}

        combatexp = (int) me->query("combat_exp");	
        for(j= sizeof(levels) - 1 ; j>=0; j--) {	
                if( atoi(levels[j])  <= combatexp ) {	
			num=j;	
			factor=10;	
			break;	
			}
		}

	if (!(tfinished =  me->query("tfinished"))) {	
		me->set("tfinished",0);					
		tfinished = 0;	
		}
	if (tfinished >= 0) 	
		num += (((int) (tfinished / 3) - (sizeof(level)-1-num))	
			? sizeof(level)-1-num : (int)(tfinished/3);	
	    else 	
		num -= ((int)(-tfinished/3)+1 - num) 	
			? num : (int)(-tfinished/3)+1;	

	tag=levels[num];
        quest = QUEST_D(tag)->query_quest();	
        timep = quest["time"];	
        time_period(timep, me);

	if (quest["quest_type"] == "杀") 	 
       	tell_object(me,"替我杀了『"+quest["quest"]+"』。\n" NOR);	 

        quest["exp_bonus"]=quest["exp_bonus"];
        quest["pot_bonus"]=quest["pot_bonus"];	      
	quest["score"]=quest["score"];	       	

        me->set("quest", quest);
        me->set("task_time", (int) time()+(int) quest["time"]);
        me->set("quest_factor",factor);
	return 1;
}

int time_period(int timep, object me)	
{
	int t, d, h, m, s;
        string time;
        
	t = timep;	
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;	 
        h = t % 24;             t /= 24;	
        d = t;	

        if(d) time = chinese_number(d) + "天";	     
	   else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";	  
        time += chinese_number(s) + "秒";	

        tell_object(me,HIW "朱鸿雪沉思了一会儿，说道：\n请在" + time + "内");	     
	return 1;
}		
