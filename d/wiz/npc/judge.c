// judge.c

#include <login.h>
#include <ansi.h>

inherit NPC;

int in_ask, answer;

void create()
{
	set_name("审判官", ({ "judge" }) );
	set("short", "专门对付机器人的" HIY "审判官" NOR "(judge)" );
	set("long",
		"这是一位审查玩家是否是机器人的审判官，你必须答对(answer)他三个问题才能\n"
		"脱离他的掌握。\n");

	set("gender", "男性");
	set("age", 40);

	set("str", 100);
	set("int", 100);
	set("cor", 100);

	set("combat_exp", 9000000);
	set("score", 0);

	set_temp("apply/attack", 200);
	set_temp("apply/damage", 500);

	setup();

	in_ask = 0;
}

void init()
{
	::init();
	if( !query_heart_beat(this_object()) ) set_heart_beat(1);
	add_action("do_answer", "answer");
}

void chat()
{
	int a, b, c;
	string oper;
	
	if( in_ask || random(20) > 10 ) return;
	delete_temp("wrong");
	a = random(100) + 1;
	b = random(100) + 1;
	switch(random(5)) {
		case 0: 
			answer = a + b;
			oper = chinese_number(a) + "加上" + chinese_number(b)+ "等于多少？";
			break;
		case 1: 
			answer = a - b;
			oper = chinese_number(a) + "减去" + chinese_number(b)+ "等于多少？";
			break;
		case 2: 
			if( a * b < 200 ) {
				answer = a * b;
				oper = chinese_number(a) + "乘上" + chinese_number(b)+ "等于多少？";
			} else {
				answer = (a * b) % 10;
				oper = chinese_number(a) + "乘上" + chinese_number(b)+ "，个位数等于多少？";
			}
			break;
		case 3: 
			answer = a % b;
			oper = chinese_number(a) + "除以" + chinese_number(b)+ "馀于多少？";
			break;
		case 4:
			oper = chinese_number(a) + "和" + chinese_number(b)+ "的最大公因数是多少？";
			if( b < a ) { c = b; b = a; a = c; }
			while( a > 1 && b%a > 1 ) {
				c = a;
				a = b%a;
				b = c;
			}
			answer = b%a == 1 ? 1 : a;
			break;
	}
	command("say " + oper + "，请在二十秒内作答(answer)。");
	in_ask = 1;
	call_out("say_answer", 20);
}

void say_answer()
{
	command("say 这么简单都不会？答案等于" + chinese_number(answer) + "。");
	in_ask = 0;	
}

int do_answer(string arg)
{
	string s;
	int ans;

	if( !in_ask ) return notify_fail("你必须等下一题。\n");
	if( !arg ) return notify_fail("请你回答一个数字。\n");

	message_vision( CYN "$N答道：" + arg + "\n" NOR, this_player());
	
	if( sscanf(arg, "%d", ans)==1 ) {
		if( ans==answer ) {
			this_player()->add_temp("robot_check", 1);
			command("say 答对了！");
			command("pat " + this_player()->query("id") );
			remove_call_out("say_answer");
			in_ask = 0;
			if( this_player()->query_temp("robot_check") >= 3 ) {
				command("say 很好，你看起来不像机器人，你可以走了。\n");
				if( stringp(s = this_player()->query_temp("old_startroom")) )
					this_player()->set("startroom", s);
				this_player()->delete_temp("robot_check");
				if( stringp(s = this_player()->query_temp("old_location")) )
					this_player()->move(s);
				else
					this_player()->move(START_ROOM);
			}
		} else {
			command("say 错！");
			add_temp("wrong/" + this_player()->query("id"), 1);
			if( query_temp("wrong/" + this_player()->query("id")) > 3 ) {
				command("say " + this_player()->name() + "你再给我乱猜啊，去死吧。\n");
				this_player()->receive_damage("kee", 100, this_object());
				this_player()->die();
			}
		}
	}
	return 1;
}
