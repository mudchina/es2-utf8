// proposer.c

inherit NPC;

string ask_for_employment();

void create()
{
	set_name("媒婆", ({ "proposer" }) );
	set("gender", "女性" );
	set("long",
		"一个打扮得花枝招展的中年妇人，如果你对哪家姑娘有意思，可以请她\n"
		"帮你去提亲。\n");
	set("attitude", "friendly");
	set("inquiry", ([
		"employment" : (: ask_for_employment :),
		"提亲" : (: ask_for_employment :),
	]) );
	set("rank_info/respect", "大娘");
	set("age", 38);
	set("env/wimpy", 100);
	setup();
	carry_object(__DIR__"obj/color_cloth")->wear();
}

string ask_for_employment()
{
	object me;

	if( query_temp("proposing") ) return 0;

	me = this_player();
	if( !me->query("can_speak") )
		return "哎哟 ... 别跟我开玩笑 ... 去找个牵猪哥的吧，呵呵呵 ...\n";
	if( (string)me->query("class")=="bonze" )
		return "啊？这位" + RANK_D->query_respect(me) + "您得先还俗吧？呵呵呵 ...\n";
	if( me->query("gender") != "男性" )
		return "这位" + RANK_D->query_respect(me) + "别心急，有点耐心慢慢等，呵呵呵 ...\n";
	command("giggle");
	if( me->query("spouce") ) 
		return "这位" + RANK_D->query_respect(me) + "您的胃口还真不小啊，呵呵呵 ...\n";
	if( query_temp("custom") )
		return me==query_temp("custom") ?
			  "是～是～ 咱们还等什么，带我去见那位姑娘吧！\n"
			: "等一会儿，待我说定这位大爷的亲事，下一个就轮到您 ...\n";
	command("say 好好好，我帮您去说(propose)准成，别忘了准备一个大红包哟 ...");
	set_leader(me);
	command("say 咱们走吧！");
	set_temp("custom", me);
}

int accept_order(object me, string verb)
{
	if( me==query_temp("custom") && verb=="propose" ) {
//		command("grin");
//		command("say 您真是贵人多忘事，这个 ... 这个 ... 准备好了吗？");
		return 1;
	}
	return 0;
}

int perform_propose(object ob)
{
	if( !ob || environment(ob)!=environment() ) {
		command("say 咦？那位姑娘人呢？");
		set_leader(query_temp("custom"));
		delete_temp("proposing");
		return 0;
	}

	switch(query_temp("proposing")) {
		case 1:
			command("whisper " + ob->query("id") + query_temp("custom")->name()
				+ "仰慕您已经很久了，特地托我来替他说亲 ...");
			add_temp("proposing", 1);
			return 1;
		case 2:
			command("whisper " + ob->query("id") + "哪 ... 就是您面前这一位，人品不错吧！");
			add_temp("proposing", 1);
			return 1;
		case 3:
			command("nod " + query_temp("custom")->query("id") );
			command("whisper " + ob->query("id") + "如果您中意，就跟我点点头(nod)吧，不然摇摇头(shake)我再去物色别的对象 ...");
			add_temp("proposing", 1);
			return 1;
		default:
			if( (int)query_temp("proposing") > 100 ) {
				command("sigh");
				command("say 看来这位姑娘根本不理我 ...");
				delete_temp("proposing");
				return 0;
			}
			switch(random(30)) {
				case 0:
					command("say " + query_temp("custom")->name()
					+ "仰慕您已经很久了，不知姑娘考虑得怎样？");
					break;
				case 1:
					command("say " + query_temp("custom")->name()
					+ "这样的人品真是不错了，姑娘您认为呢？");
					break;
				case 2:
					command("whisper " + ob->query("id") 
					+ "如果您中意，就点点头(nod)吧，不然摇摇头(shake)我再去物色别的对象 ...");
					break;
				case 3:		command("smile"); break;
				case 4:		command("giggle"); break;
				case 5:		command("hmm"); break;
			}
			add_temp("proposing", 1);
			return 1;
	}
}

int force_me(string cmd)
{
	object me, ob;
	string target;

	if( sscanf(cmd, "propose %s", target) ) {
		me = this_player(1);
		ob = present(target, environment());
		if( !ob || !userp(ob) || !ob->query("can_speak")
		||	(string)ob->query("gender") != "女性") {
			command("?");
			command("say 谁？您中意的姑娘是哪一位？");
			return 0;
		}
		if( ob->query("spouce") ) {
			command("whisper " + me->query("id") + "人家可是有夫之妇哟，您还是考虑考虑吧！");
			return 0;
		}
		command("smile");
		command("whisper " + me->query("id") + " 您放心，看我的！");
		command("smile " + ob->query("id"));
		set_temp("proposing", 1);
		set_leader(ob);
		start_busy( (: perform_propose, ob :) );
		return 1;
	}
	else return ::force_me(cmd);
}

int accept_object(object me, object obj)
{
}

void end_duty()
{
}
