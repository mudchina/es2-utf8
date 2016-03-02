// teacher.c

inherit NPC;

void follow_player();

void create()
{
	set_name("魏无极", ({ "teacher", "wey" }) );
	set("title", "教书先生");
	set("gender", "男性" );
	set("age", 47);
	set("int", 26);
	set("long",
		"魏无极是个博学多闻的教书先生，他年轻时曾经中过举人，但是\n"
		"因为生性喜爱自由而不愿做官，魏无极以教书为业，如果你付他\n"
		"一笔学费，就可以成为他的弟子学习读书识字。\n");
	set("inquiry", ([
		"学费": ({
			"嗯 ... 读书识字是做人的第一步。",
			"学好了读书识字的本领，胜过于百万的家财。",
			"所以说学问是金钱买不到的。",
			0,
			0,
			0,
			(: command, "hmm" :),
			"虽然学问是无价的，不过如果你有心的话 ...",
			"只要五两银子。",
			}),
		"读书识字": "对，读书识字。",
		"刘安禄": ({
			"哦 ... 你是说野羊山寨的二寨主，人称血手刘三的刘安禄吗？",
			"他又出来做恶了？",
			(: command, "hmm" :),
			"你带我去见他，让我跟他说几句话。",
			(: follow_player :),
			})
	]) );
	set("attitude", "peaceful");
	set_skill("literate", 60);
	setup();
}

void follow_player()
{
	object ob;

	if( !objectp(ob = query_temp("last_asker")) ) return;
	set_leader(ob);
}

int recognize_apprentice(object ob)
{
	if( !ob->query("marks/魏无极") ){
		say("魏无极说道：咦？我不记得收过你这个学生啊....\n");
		return 0;
	}

	return 1;
}

int accept_object(object who, object ob)
{
	if( !who->query("marks/魏无极") ) {
		if( ob->value() >= 500 ) {
			say("魏无极点了点头，说道：很好，从今天起你随时可以来问我有关读书识字(literate)\n"
				"                      的任何问题。\n");
			who->set("marks/魏无极", 1);
			return 1;
		} else {
			say("魏无极说道：你的诚意不够，这钱还是拿回去吧。\n");
			return 0;
		}
	} else
		say("魏无极点了点头，说道：哦，向你这么有心的学生还真是不多见，好好努力\n"
			"                      将来必定前途无量，谢了。\n");
	return 1;
}

int accept_learn(object me, string skill)
{
	return 1;
}
