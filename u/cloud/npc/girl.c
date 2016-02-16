// girl.c

inherit NPC;

void create()
{
	set_name("李师师", ({ "girl" }) );
	set("title", "名妓");
	set("gender", "女性" );
	set("age", 22);
	set("str", 10);
	set("per", 30);
	set("long", @LONG
    李师师是怡红院的名妓，精通琴棋书画，周围的纨绔子弟们常往这
里钻。
LONG
);
	set("combat_exp", 10);
	set("attitude", "friendly");

        set("chat_chance_combat", 25);
        set("chat_msg_combat", ({
"李师师秀眉微蹙，说道：喂！我哪里得罪您了？干嘛这样跟我拼死拼活？\n",
	}) );

	set_skill("literate", 100);

	set("inquiry", ([
		"过夜": "官人可要洁身自好啊！",
		"嫖妓": "官人可要洁身自好啊！",
		"学艺": "请您留件信物！",
	]) );

	setup();
	
	carry_object("/u/cloud/obj/npc/girl/pink_cloth")->wear();
}

int recognize_apprentice(object ob)
{
        if( !ob->query("marks/李师师") ) {
                say("李师师说道：咦？我不记得您啊......\n");
                return 0;
        }
        return 1;
}

int accept_object(object who, object ob)
{
	if( ob->value() ){
		command("say 我对钱没兴趣！");
                return 0;
        }

	if( (this_player()->query("per") < 25) 
		|| ( (string)this_player()->query("gender") == "女性") ){
		command("say 我对您没兴趣！");
		return 0;
	}
	command("say 能做相公的老师，真是三生有幸。");
	who->set("marks/李师师", 1);
        return 1;
}

int accept_fight(object me)
{
	command("say 小女子哪里是您的对手？");
	return 0;
}

