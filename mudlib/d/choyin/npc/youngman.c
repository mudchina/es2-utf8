// youngman.c

inherit NPC;

void create()
{
	set_name("贵公子", ({ "youngman" }) );
	set("long", "一个相貌俊美的年轻贵公子正优雅地欣赏著窗外的景物。\n");
	set("age", 22);
	set("attitude", "peaceful");
	set("combat_exp", 2500);
	set("env/wimpy", 50);
	set("str", 20);
	set("cor", 26);
	set("cps", 26);
	set("per", 29);
	set("inquiry", ([
		"name": "在下姓游，单名一个晋字，不知阁下如何称呼？",
		"here": "这里是乔阴县城，您是外地来的吧？",
		"trouble": ({
			(: command, "hmm" :),
			"实不相瞒，在下仰慕前面曲桥上赏莲的姑娘已久 ...",
			"但是一直不知那位姑娘芳名 ...",
			"唉 ..."
			}),
		"姑娘" : "就是那位绿裙黄衫的姑娘 ...",
	]) );
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("sword", 40);
	setup();
	carry_object(__DIR__"obj/hat")->wear();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/longsword")->wield();
}

int accept_object(object me, object ob)
{
	if( !ob->id("###silk bag###") ) return 0;
	message("vision", name() + "一眼瞥见荷包上的鸳鸯图案，立刻一把抢了过去。\n"
		+ name() + "随即从怀中掏出一方手帕，上面竟也绣著一幅相同的鸳鸯图。\n", environment());
	command("say 原来爹爹替我主张的婚事，竟然是 ...");
	command("jump");
	delete("inquiry/trouble");
	return 1;	
}
