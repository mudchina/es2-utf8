// master.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_for_join();

void create()
{
	set_name("玄智和尚", ({ "master bonze", "master", "bonze" }) );

	set("gender", "男性");
	set("age", 74);
	set("attitude", "peaceful");
	set("class", "bonze");
	set("apprentice_available", 10);

	set("str", 17);
	set("int", 30);
	set("spi", 30);
	set("con", 30);
	set("cps", 30);
	set("cor", 20);

	set("atman", 2000);
	set("max_atman", 2000);

	set("force", 1500);
	set("max_force", 1500);
	set("force_factor", 5);

	set("mana", 600);
	set("max_mana", 600);

	set("combat_exp", 1000000);
	set("score", 9000);

	set("inquiry", ([
		"剃度" : (: ask_for_join :),
		"出家" : (: ask_for_join :),
	]) );

	set_skill("staff", 100);
	set_skill("unarmed", 80);
	set_skill("force", 100);
	set_skill("dodge", 30);
	set_skill("literate", 60);
	set_skill("chanting", 100);
	set_skill("parry", 50);
	set_skill("magic", 100);

	set_skill("cloudstaff", 100);
	set_skill("lotusforce", 100);
	set_skill("buddhism", 100);
	set_skill("essencemagic", 100);

	map_skill("staff", "cloudstaff");
	map_skill("parry", "cloudstaff");
	map_skill("force", "lotusforce");
	map_skill("magic", "essencemagic");

	create_family("山烟寺", 26, "住持");

	setup();

	carry_object(__DIR__"buddha_staff")->wield();
}

void init()
{
	add_action("do_kneel", "kneel");
}

string ask_for_join()
{
	object me;

	me = this_player();

	if( (string)me->query("class")=="bonze" )
		return "阿弥陀佛！你我同是出家人，何故跟老衲开这等玩笑？\n";
	if( (string)me->query("gender") != "男性" )
		return "阿弥陀佛！女施主，这里是寺庙，请□到尼庵去剃度吧。\n";

	me->set_temp("pending/join_bonze", 1);
	return "阿弥陀佛！善哉！善哉！施主若真心皈依我佛，请跪下(kneel)受戒。\n";
}

int do_kneel()
{
	string *prename =
	 ({ "空", "明", "圆", "净", "虚", "悟",
		"方", "渡", "慧", "法" });
	string name, new_name;

	if( !this_player()->query_temp("pending/join_bonze") ) return 0;
	message_vision(
		HIC "$N双手合十，恭恭敬敬地跪了下来。\n\n"
			"$n伸出手掌，在$N头顶轻轻地摩挲了几下，将$N的头发尽数剃去。\n\n" NOR,
		this_player(), this_object() );
	name = this_player()->query("name");
	new_name = prename[random(sizeof(prename))] + name[0..1];
	command("say 从今以後你的法名叫做" + new_name + "。");
	command("smile");
	this_player()->delete_temp("pending/join_bonze");
	this_player()->set("name", new_name);
	this_player()->set("class", "bonze");

	return 1;
}

void attempt_apprentice(object ob)
{
	if( query("apprentice_available") ) {
		if( find_call_out("do_recruit") != -1 )
			command("say 慢著，一个一个来。");
		else
			call_out("do_recruit", 2, ob);
	} else {
		command("say 老纳今天已经收了十个弟子，不想再收徒了。");
	}
}

void do_recruit(object ob)
{
	if( (string)ob->query("gender") != "男性" )
		command("say 阿弥陀佛，女施主不要跟老纳开玩笑。");
	else if( (string)ob->query("class") != "bonze" )
		command("say 阿弥陀佛，施主愿入佛门，请先到小寺剃度出家。");
	else {
		command("say 阿弥陀佛，善哉！善哉！");
		command("recruit " + ob->query("id") );
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) ) {
		add("apprentice_availavble", -1);
		return 1;
	}
}

int accept_fight(object me)
{
	if( (string)me->query("class")=="bonze" )
		command("say 阿弥陀佛！出家人戒逞强恶斗！老衲不敢违反清规。");
	else
		command("say 施主既然身负绝艺，老衲佩服便是，也不必较量了。");
	
	return 0;
}
