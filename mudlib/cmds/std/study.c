// study.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object ob;
	mapping skill;
	int cost;

	if( me->is_fighting() )
		return notify_fail("你无法在战斗中专心下来研读新知！\n");

	if(!arg || !objectp(ob = present(arg, me)) )
		return notify_fail("你要读什麽？\n");

	if( !mapp(skill = ob->query("skill")) )
		return notify_fail("你无法从这样东西学到任何东西。\n");

	if( !me->query_skill("literate", 1) )
		return notify_fail("你是个文盲，先学学读书识字(literate)吧。\n");

	message("vision", me->name() + "正专心地研读" + ob->name()
		+ "。\n", environment(me), me);

	if( (int)me->query("combat_exp") < skill["exp_required"] ) {
		write("你的实战经验不足，再怎麽读也没用。\n");
		return 1;
	}

	notify_fail("以你目前的能力，还没有办法学这个技能。\n");
	if( !SKILL_D(skill["name"])->valid_learn(me) ) return 0;

	cost = skill["sen_cost"] + skill["sen_cost"] 
		* (skill["difficulty"] - (int)me->query("int"))/20;
	if( (int)me->query("sen") < cost ) {
		write("你现在过於疲倦，无法专心下来研读新知。\n");
		return 1;
	}

	if( me->query_skill(skill["name"], 1) > skill["max_skill"] ) {
		write("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
		return 1;
	}

	me->receive_damage("sen", cost);

	if( !me->query_skill(skill["name"], 1) )
		me->set_skill(skill["name"], 0);
	me->improve_skill(skill["name"], (int)me->query_skill("literate", 1)/5+1);
	write("你研读有关" + to_chinese(skill["name"]) + "的技巧，似乎有点心得。\n");
	return 1;
}

int help(object me)
{
   write( @HELP
指令格式: study <物品名称>

这个指令使你可以从秘笈或其他物品自学某些技巧,
但前提是: 你不能是个『文盲』。

see also : learn
HELP
   );
   return 1;
}
