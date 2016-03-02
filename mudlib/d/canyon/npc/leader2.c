// leader.c

inherit NPC;

void create()
{
	set_name("老队长", ({ "leader" }));
	set("gender", "男性");
	set("age", 30);
	set("long",
        	"不苟言笑的样子，带领著小兵驻守隘口的小队长。\n");

	set("attitude", "peaceful");

	set("str", 27);
	set("int", 25);

	set("combat_exp", 80000);
	
	set("chat_chance", 8);
	set("chat_msg", ({
	"老队长说道：大队长对这个地方好熟，还常常说些这□的故事给我们听。\n",
	"老队长说道：你有没有搞错啊！来这□不给我们大队长过路费，你找死啊！\n",
	"老队长说道：兵器库入口处的阵法真是厉害，一般人绝对找不到的。\n",
	}) );
	
	set("inquiry", ([
		"黄石隘口" : "你问问大队长吧，我不是很清楚。\n",
		"后备兵" : "后备兵就..........你想做什么？找死啊。\n",
	]) );
	
	set("force", 400);
	set("max_force", 400);
	set("force_factor", 5);

	set_skill("dodge", 60);
	set_skill("blade", 60);
	set_skill("parry", 60);
	set_skill("force", 60);
	set_skill("unarmed", 65);
	
	setup();

	carry_object( __DIR__"obj/blade")->wield();
}

		
