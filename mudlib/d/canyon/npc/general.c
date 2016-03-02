// general.c

#include <ansi.h>

inherit NPC;

//#define PATH "/u/t/tnn/canyon/camp2"
#define PATH "/d/canyon/camp2"

void create()
{
	set_name("严廷殷", ({ "master general","master","general" }) );
	set("title", "天邪派第十六代弟子");
	set("nickname", YEL "镇国大将军" NOR);
	set("gender", "男性");
	set("age", 45);
	set("long",
        	"容光焕发，左佩刀，右佩剑，威风□□，其高七尺六寸，虎背\n"
        	"熊腰，年轻时同和大天邪于兰天武同拜一师，武功\造诣不在大\n"
        	"天邪之下，但志向不同，后成了京师武功\第一、人人称羡的镇\n"
        	"国大将军。\n");

	set("attitude", "peaceful");

	set("str", 29);
	set("int", 28);

	set("inquiry",([
		"黄石隘口" : "你眼睛脱窗啊，这□就是黄石隘口。\n",
		"后备兵" : "我不管这种事的，你别来烦我。\n",
		"兵器库" : "你找死啊！问这种问题，你想干麻啊。\n",
		"印鉴" : "你怎么知道的？帮我找找吧，找到了我送你礼物。\n",
	]) );
	set("force", 1800);
	set("max_force", 1800);
	set("force_factor", 20);
	set("max_gin", 200);
	set("eff_gin", 200);
	set("gin", 200);
	set("max_sen", 200);
	set("eff_sen", 200);
	set("sen", 200);
	
	set("combat_exp", 900000);

        set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );
	
	set_skill("sword", 80);
	set_skill("six-chaos-sword", 85);
	set_skill("force", 80);
	set_skill("celestial", 80);
	set_skill("parry", 50);
	set_skill("dodge", 60);
	set_skill("pyrobat-steps", 60);
	set_skill("unarmed", 80);
	set_skill("celestrike", 85);
	
	map_skill("sword", "six-chaos-sword");
	map_skill("parry", "six-chaos-sword");
	map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");
	map_skill("dodge", "pyrobat-steps");
	
	
	setup();

	carry_object( __DIR__"obj/broken_sword")->wield();
//carry_object( __DIR__"obj/broken_sword")->wield();
	carry_object( __DIR__"obj/cloud_armor")->wear();

}

int accept_object(object who,object ob)
{
	object obj;

	if ( (string)ob->name() == "[1;33m印鉴[0m") {
		command("say 真是谢谢你了。");
		command("smile");
		command("say 为了答谢你，这把古剑送你，当做报酬吧。");
//		obj=new(__DIR__"obj/old_sword");
                obj=new("/d/canyon/npc/obj/old_sword");
		obj->move(who);
//		call_out( (: destruct :), 1, ob);
 		return 1;
 	}
 	
	if ( (string)ob->name() == "印鉴" ) {
		command("say 你拿给我的是什么东西啊!");
 		command("say 别想拿这种东西来骗我");
		command("say 给我滚出去");
 		who->set_temp("将军/kick", 1);
		who->move(PATH);
		return 0;
	}
	
	if ( !ob->value() ) {
		command("say ㄟ....Ｔhank Ｙou!!!");
		command("grin");
//		call_out( (: destruct :), 1, ob);
		return 1;
	}
	
	command("say 啊，真是谢谢你了。");
	return 1;
}
