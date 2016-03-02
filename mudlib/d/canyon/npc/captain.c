// captain.c

#include <ansi.h>

inherit NPC;

string tell_story(object who);

string *make_msg = ({
    HIG"二十多年前，先帝将大将军们调来这□驻守隘口。\n\n"NOR,
    HIG"京城的也就因隘口的巩固而获得安全。\n\n"NOR,
    HIG"事隔多年，先帝也死了，换上的是位我们不甚认识的小皇帝。\n\n"NOR,
    HIG"看来他只忙著找剑，也没什么大作为，大家也不太服他。\n\n"NOR,
    HIG"皇帝看到大将军还要敬畏三分ㄌㄟ。\n\n"NOR,
    HIG"反正啊，将军和军师是超强的，你可要好好的乌西我们才行。\n\n"NOR,
    HIG"知道了，就快缴钱。\n"NOR,
});

void create()
{
	set_name("大队长", ({ "captain" }));
	set("gender", "男性");
	set("age", 30);
	set("long",
        	"他不苟言笑的样子，带领著小兵驻守隘口的队长。\n");

	set("attitude", "peaceful");

	set("str", 27);
	set("int", 25);

	set("combat_exp", 120000);

	set("inquiry", ([
		"允许" : "先给钱再说吧。\n",
		"兵器库" : "喔！那是我们厉害的军师所设的阵法。\n",
		"黄石隘口" : (: tell_story :),
	]) );
	
	set("chat_chance", 8);
	set("chat_msg", ({
		"大队长说道：有没有问题要问我啊？\n",
		"大队长说道：我对这□很熟的喔。\n",
	}) );
	
	set("force", 700);
	set("max_force", 700);
	set("force_factor", 5);

	set_skill("dodge", 70);
	set_skill("sword", 70);
	set_skill("parry", 70);
	set_skill("force", 70);
	set_skill("unarmed", 65);
	
	setup();

	carry_object( __DIR__"obj/sword")->wield();
	carry_object( __DIR__"obj/armor")->wear();
}

int accept_object(object who, object ob)
{
        if ( !ob->value() ) {
        	command("say ㄟ....Ｔhank Ｙou!!!");
                command("grin");
        //        call_out( (: destruct :), 1, ob);
                return 1;
        }
                                                                                
	if ( !who->query("marks/军营") ) {
		if( ob->value() >=3000 ) {
			say("大队长说道:我已帮你列入名册了，从今天你可自由"
				"地出入营区了。\n");
			who->set("marks/军营",1);
			return 1;
		} else {
			say("大队长说道:你的诚意不够喔，再多缴点吧。\n");
			return 1;
		}
	} else
		say("大队长说道:哦喔！还真有心啊，真是谢谢你了。\n");
	
	return 1;
}

string tell_story(object who)
{
	who=this_player();
	call_out( "make_stage", 2, who, 0 );
	return 0;
}

void make_stage(object who,int stage)
{
	tell_object(who,make_msg[stage]);
	if (++stage < sizeof(make_msg) ) {
		call_out( "make_stage", 2, who, stage);
		return;
	}
	return;
}
         
		
