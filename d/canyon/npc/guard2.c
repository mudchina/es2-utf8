// shiao.c

inherit NPC;

void create()
{
	set_name("老兵", ({ "guard" }) );
	set("gender", "男性");
	set("age", 24);
	set("long",
        	"风沙满面，无精打采，毫无生气的样子，真难以想像是这\n"
                "□的守军。\n");

	set("attitude", "peaceful");

	set("str", 26);
	set("int", 24);

	set("combat_exp", 40000);
	
	set("chat_chance", 15);
	set("chat_msg",({
		"老兵说道：军师真是神算啊，把那狗贼都吓的不敢再来了。\n",
		"老兵说道：听说那个后备兵捡到了一个黄澄澄的宝物。\n",
		"老兵说道：嘿！有没有钱啊？挡点□来花花吧！\n",
	}) );
	
	set("inquiry", ([
		"黄石隘口" : "这个问题问我们大队长比较知道。\n",
		"后备兵" : "嘿嘿！你想做啥？\n",
		"军火库" : "你问这个喔..........不予回答。\n",
	]) );
	
	set("force", 300);
	set("max_force", 300);
	set("force_factor", 5);
	
	set_skill("unarmed", 40);
	set_skill("parry", 60);
	set_skill("dodge", 50);

	setup();

}
