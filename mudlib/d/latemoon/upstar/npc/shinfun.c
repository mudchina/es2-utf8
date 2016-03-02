inherit NPC;
string do_reply();
 
void create()
{
        set_name("莫欣芳" , ({ "shinfun","fun","girl" }) );
        set("gender", "女性" );
        set("age", 27);
        set("long", @TEXT
她国色天香，娇丽无伦；温柔娴静，秀绝人寰。
她姿容绝美，世所罕见。从她身旁你闻道一寒谷
幽香。
TEXT
);
	set("inquiry", ([
		"舞曲谱":
		(: this_object(), "do_reply" :),
	]) );
       set("class", "dancer");
       set("combat_exp", 200000);
        set_skill("unarmed", 50);
        set_skill("dodge", 70);
        set_skill("stormdance", 50);
        set_skill("tenderzhi", 70);
        set_skill("force",50);
        map_skill("dodge","stormdance");
        map_skill("unarmed","tenderzhi");
        set("force", 1000);
        set("max_force", 500);
       set_temp("apply/armor", 70);
       set_temp("apply/attack", 50);

        create_family("晚月庄",2,"弟子");
        setup();
        carry_object("/d/latemoon/obj/deer_boot")->wear();
        carry_object("/d/latemoon/obj/belt")->wear();
        carry_object("/d/latemoon/obj/clasp")->wear();
}

string do_reply()
{
	this_player()->set("mark/dance-book",1);
	return("舞曲谱啊，师姐她们练习舞步的时候才用的着，\n"+
"你也想学吗？ 嘻嘻...\n");
}

