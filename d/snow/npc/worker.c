// worker.c

inherit NPC;

void create()
{
	set_name("苦力", ({ "worker" }) );
	set("gender", "男性" );
	set("long", "一个苦力打扮的汉子在这里等人来雇用(employment)。\n");
	set("attitude", "friendly");
	set("inquiry", ([
		"employment": "小人的工资一天只要一百文钱，大人只管吩咐。",
		"name": "小人的名字难听得紧，不敢劳大人过问。",
		"home": "小人是乔阴县雪亭镇人氏。",
	]) );
	set("age", 27);
	set("str", 27);
	set("env/wimpy", 100);
	setup();
	carry_object("/obj/cloth")->wear();
}

int accept_order(object me, string verb)
{
	if( (string)me->query("id") == (string)query("boss_id") ) {
		switch(verb) {
			case "kill":
				command("say 小人家有老母妻小，这个 .... 这个 ....");
				return 0;
			case "fight":
				command("say 小人不会武功\，" + RANK_D->query_respect(me)
					+ "您说笑了。\n");
				return 0;
			default:
				return 1;
		}
	}
	return 0;
}

int accept_info(object me, string command)
{
	return (string)me->query("id") == (string)query("boss_id");
}

int accept_object(object me, object obj)
{
	if( query("boss_id") ) {
		command("say 对不起，小的已经有人雇了。");
		return 0;
	}

	if( (int)obj->value() < 100 ) {
		command("say 一百文钱一天，一个子儿也不能少。");
		return 0;
	}
	set("boss_id", me->query("id"));
	call_out("end_duty", (obj->value()/100) * 1440 );
	command("say 谢谢" + RANK_D->query_respect(me) +"！有什么事只管吩咐！\n");
	command("follow " + me->query("id"));
	return 1;
}

void end_duty()
{
	command("tell " + query("boss_id") + " 小的下工时间到了。");
	command("bow");
	delete("boss_id");
}
