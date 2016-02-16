//traveller.c
inherit NPC;

void create()
{
        set_name("游客", ({ "visitor"}));
        if(random(10)<7)
            set("gender", "男性" );
        else
            set("gender", "女性" );
        set("age", 15+random(50));
        set("long",
	"这是一位来乔阴县游玩的游客。\n");

	set("env/wimpy",20);
	set("max_kee",1000);
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set_skill("dodge", 90);
        set_skill("unarmed", 76);
	set("str",20);
	set("cor",50);
	set_temp("apply/armor",30);
	
	set ("inquiry", ([
		"here": "我游历过大半个中国，小小的乔阴县对我能有什么秘密？\n",
		"忘忧草": "这个。。好象是给狮子衔去了。\n",
		]) );

        setup();
        carry_object("/obj/cloth")->wear();
        add_money("silver", 5);
}



