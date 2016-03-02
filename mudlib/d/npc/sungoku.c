// sangoku.c

#include <ansi.h>

inherit NPC;
inherit F_SAVE;

void create()
{
	set_name( "孙悟空", ({ "sun goku", "sun", "goku" }) );
	if( !restore() ) {
		set("short", "来自「七龙珠」的" HIC "孙悟空" NOR "(Sun goku)");
		set("long",
			"孙悟空是来自鸟山明的漫画「七龙珠」，你别小看他现在一付傻头傻脑的样子\n"
			"，他可是 ESII 第一个自我成长型的 NPC，从他被创造出来以后，他所获得的\n"
			"战斗经验都会储存下来。\n" );
		set("gender", "男性" );
		set("race", "赛亚人");
		set("chat_chance", 15);
		set("chat_msg", ({
			(: this_object(), "random_move" :),
			CYN "孙悟空说道：哈罗！来比武吧？\n" NOR,
			CYN "孙悟空翻了个跟斗，用一只手指撑在地下，说道：这招你会不会啊？\n" NOR,
		}) );
		set("chat_msg_coombat", ({
			CYN "\n孙悟空扮个鬼脸，说道：来呀！再来呀！\n" NOR,
			CYN "\n孙悟空说道：这一招是爷爷教我的，厉害吧！\n" NOR,
		}) );

		// We have 7 pills per reset.
		set("pills", 7);

		// This is the initial apply for his race.		
		set("perm_apply", ([
			"attack":	10,
			"dodge":	10,
			"damage":	5,
		]) );

		set("age", 9);
		set("str", 44);
		set("cor", 24);
		set("cps", 18);
		set("per", 24);
		set("int", 42);

		set_skill("unarmed", 1);
		set_skill("dodge", 1);
		set_skill("force", 1);
		set_skill("parry", 1);
	}

	set_temp("apply", query("perm_apply"));
	setup();
	carry_object(__DIR__"obj/kame_suit")->wear();
}

string query_save_file()
{
	return __DIR__"data/sungoku";
}

void reset()
{
	int learn;

	// Restore the pills.
	set("pills", 7);

	// Improve sungoku's natural ability if there's potential available.
	if( (int)query("potential") > (int)query("learned_points") ) {
		learn = (int)query("potential") - (int)query("learned_points");
		add_temp("apply/attack", learn / 3);
		add_temp("apply/dodge", learn / 3);
		add_temp("apply/damage", learn / 3);
		add("learned_points", (learn / 3) * 3);
	}

	save();
}

int accept_fight(object who)
{
	if( is_fighting() ) {
		if( random(query("eff_kee")) > (int)query("kee") ) {
			say( CYN "孙悟空大叫：这么多人我打一个？不行不行，等我打败这些人再跟你打！\n" NOR);
			return 0;
		} else {
			say( CYN "孙悟空大叫：这么多人我打一个？没关系，我一定让你们好看！\n" NOR);
			return 1;
		}
	}
	say( CYN "孙悟空很高兴地说道：好啊，好啊，我要出招了...\n" NOR);
	return 1;
}

int receive_damage(string type, int pts)
{
	int damage;

	damage = ::receive_damage(type, pts);
	if( (type=="kee") && (damage > (int)query("max_kee") / 5) ) {
		say( CYN "孙悟空捂著受伤的地方，说道：好痛啊...真有你的....\n" NOR);
		if( random(query("kee")) < damage)
			random_move();
	}

	if( (int)query("pills")
	&&	(((int)query("kee")) < 20 
		|| ((int)query("gin") < 20) 
		|| ((int)query("sen") < 20) )) {
		say( HIY "孙悟空从口袋摸出一粒花梨塔猫仙人给他的仙豆吞了下去。\n" NOR);
		set("gin", query("eff_gin"));
		set("kee", query("eff_kee"));
		set("sen", query("eff_sen"));
		add("pills", -1);
	}
	return damage;
}

varargs void improve_skill(string skill, int amount, int raw)
{
	// Thus we can gain skill levels from direct fighting.
	::improve_skill(skill, amount);
}

void revive()
{
	// This is a feature of sungoku's race. See the comic :P.
	add("combat_exp", (int)query("combat_exp") / 3 + 10);
	reset();
	::revive();
}

void kill_ob(object ob)
{
	fight_ob(ob);
}

void defeated_enemy(object ob)
{
	say(CYN "孙悟空作出一个 V 字型的手势，说道：我赢了！" NOR);
	remove_killer(ob);
}
