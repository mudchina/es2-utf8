// beast.c

#include <race/beast.h>

mapping combat_action =
([
	"hoof": ([
		"action":		"$N用後腿往$n的$l用力一蹬",
		"damage":		100,
		"damage_type":	"瘀伤",
	]),
	"bite": ([
		"action":		"$N扑上来张嘴往$n的$l狠狠地一咬",
		"damage":		20,
		"damage_type":	"咬伤",
	]),
	"claw": ([
		"action":		"$N用爪子往$n的$l一抓",
		"damage_type":	"抓伤",
	]),
	"poke": ([
		"action":		"$N用嘴往$n的$l一啄",
		"damage":		30,
		"damage_type":	"刺伤",
	]),
]);

string *actions;

void create()
{
	actions = keys(combat_action);
}

void setup_beast(object ob)
{
	mapping my;

	my = ob->query_entire_dbase();

	my["unit"] = "只";

	if( undefinedp(my["actions"]) ) {
		if( pointerp(my["verbs"]) )
			ob->set("default_actions", (: call_other, __FILE__, "query_action" :) );
		else
			my["default_actions"] = ([
				"action": "$N攻击$n的%s，%s\n",
			]);
	}
	
	if( undefinedp(my["gender"]) ) my["gender"] = "雄性";
	if( undefinedp(my["age"]) ) my["age"] = random(40) + 5;

	if( undefinedp(my["str"]) ) my["str"] = random(41) + 5;
	if( undefinedp(my["cor"]) ) my["cor"] = random(21) + 5;
	if( undefinedp(my["int"]) ) my["int"] = random(11) + 5;
	if( undefinedp(my["spi"]) ) my["spi"] = 0;
	if( undefinedp(my["cps"]) ) my["cps"] = random(11) + 5;
	if( undefinedp(my["per"]) ) my["per"] = random(31) + 5;
	if( undefinedp(my["con"]) ) my["con"] = random(41) + 5;

	if( undefinedp(my["max_gin"]) ) {
		if( my["age"] <= 3 ) my["max_gin"] = 50;
		else if( my["age"] <= 10 ) my["max_gin"] = 50 + (my["age"] - 3) * 20;
		else if( my["age"] <= 30 ) my["max_gin"] = 190 + (my["age"] - 10) * 5;
		else my["max_gin"] = my["max_gin"] = 290 + (my["age"] - 30);
	}
	if( undefinedp(my["max_kee"]) ) {
		if( my["age"] <= 5 ) my["max_kee"] = 50;
		else if( my["age"] <= 20 ) my["max_kee"] = 50 + (my["age"] - 5) * 25;
		else my["max_kee"] = my["max_kee"] = 425 + (my["age"] - 20) * 5;
	}
	if( undefinedp(my["max_sen"]) ) {
		if( my["age"] <= 20 ) my["max_sen"] = 50;
		else my["max_sen"] = 50 + (my["age"] - 20) * 10;
	}

	//	NOTE: beast has no initial limbs defined, you must define it yourself.
	//	ob->init_limbs(LIMBS);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);
}

mapping query_action(object me)
{
	string *act;

	act = me->query("verbs");
	return combat_action[act[random(sizeof(act))]];
}
