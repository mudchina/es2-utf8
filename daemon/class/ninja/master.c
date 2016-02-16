
// master.c
inherit NPC;
inherit F_MASTER;
void create()
 {
	set_name("逍遥子", ({ "master happyman", "happyman", "master" }) );
	set("nickname", "笑红尘");
	set("gender", "男性" );
	set("age", 41);
	set("str", 27);
	set("cor", 30);
	set("cps", 20);
	set("int", 30);
	set("per", 30);
	set("con", 30);
	set("kar", 30);
	set("max_force", 2000);
	set("force", 2000);
	set("force_factor", 20);
	set("rank_info/respect", "无崖子");
	set("long",
		"逍遥子是个容貌俊美，风流倜傥的青年人，只看外表，你怎么\n"
		"也猜不到他有４０岁了，只见他面如冠玉，一袭青衫更显得潇\n"
		"洒无比，一双似笑非笑的眼睛，突然向你看了一眼，你不禁心\n"
		"中一动。\n");
	create_family("逍遥派", 4, "掌门人");
	set("combat_exp", 2000000);
	set("score", 300000);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		"红尘多可笑，痴情最无聊\n",
		"凭谁知，多情总被无情恼\n",
		"对酒当歌，人生几何\n",	}) );
        set_skill("unarmed", 150);
     	set_skill("parry", 120);
	set_skill("dodge", 150);
	set_skill("sword", 100);
	set_skill("force", 150);
	set_skill("literate", 150);
	set_skill("wu-shun", 120);
	set_skill("linbo-steps", 150);
	set_skill("ts-fist", 120);
	map_skill("unarmed", "ts-fist");
	map_skill("force", "wu-shun");
        map_skill("dodge", "linbo-steps");
	set("inquiry", ([
		"逍遥派" : "逍遥派门户由我执掌，你有何指教？",
		"拜师"   : "入我派者，需人品文采，无一不是上上之选。",
         	"name": "我便是逍遥子，快乐逍遥，人生几何。",
		"here": "这里便是娘环福地。",	]) );
	        setup();
        	carry_object(__DIR__"seven_belt")->wear();
        	carry_object(__DIR__"green_dress")->wear();
      }
   
void attempt_apprentice(object ob)
 {
	if( ((int)ob->query("per") < 25)) 
          {     command("say 入我派者，需人品文采，无一不是上上之选。" +
              RANK_D->query_respect(ob) + "的资质不宜！");
               return; }
                         
        if (  ((int)ob->query_skill("literate",1) < 50) ) 
	  {	command("say 入我派者，需人品文采，无一不是上上之选。" + 
              RANK_D->query_respect(ob) + "的文采不宜！");
		return;	}

	if((string)ob->query("title")!="普通百姓")
       	 {
	    command("chat "+ob->query("title")+ob->query("nickname")+
            ob->query("name")+"要叛师！！！");	 
            command("grin");
	    kill_ob(ob);
	    return;
	 }

	command("smile");
	command("say 很好" + RANK_D->query_respect(ob) + 
        "多加努力他日必定有成。\n");
	command("recruit " + ob->query("id") );}
 
void recruit_apprentice(object ob)
         {
        	if( ::recruit_apprentice(ob) )
        	ob->set("class", "fighter");
        }
