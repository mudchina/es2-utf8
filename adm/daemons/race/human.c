// human.c

// A normal human is at least 40 kg weight
#define BASE_WEIGHT 40000

inherit F_DBASE;

mapping *combat_action = ({
	([	"action":		"$N挥拳攻击$n的$l",
		"damage_type":	"瘀伤",
	]),
	([	"action":		"$N往$n的$l一抓",
		"damage_type":	"抓伤",
	]),
	([	"action":		"$N往$n的$l狠狠地踢了一脚",
		"damage_type":	"瘀伤",
	]),
	([	"action":		"$N提起拳头往$n的$l捶去",
		"damage_type":	"瘀伤",
	]),
	([	"action":		"$N对准$n的$l用力挥出一拳",
		"damage_type":	"瘀伤",
	]),
});

void create()
{
	seteuid(getuid());
	set("unit", "位");
	set("gender", "男性");
	set("can_speak", 1);
	set("attitude", "peaceful");
	set("limbs", ({
		"头部",	"颈部",	"胸口",	"後心",	"左肩",	"右肩",	"左臂",
		"右臂",	"左手",	"右手",	"腰间",	"小腹",	"左腿",	"右腿",
		"左脚",	"右脚"
	}) );
}

void setup_human(object ob)
{
	mapping my;

	my = ob->query_entire_dbase();

	ob->set("default_actions", (: call_other, __FILE__, "query_action" :));
	
	if( undefinedp(my["age"]) ) my["age"] = random(30) + 15;

	if( undefinedp(my["str"]) ) my["str"] = random(21) + 10;
	if( undefinedp(my["cor"]) ) my["cor"] = random(21) + 10;
	if( undefinedp(my["int"]) ) my["int"] = random(21) + 10;
	if( undefinedp(my["spi"]) ) my["spi"] = random(21) + 10;
	if( undefinedp(my["cps"]) ) my["cps"] = random(21) + 10;
	if( undefinedp(my["per"]) ) my["per"] = random(21) + 10;
	if( undefinedp(my["con"]) ) my["con"] = random(21) + 10;
	if( undefinedp(my["kar"]) ) my["kar"] = random(21) + 10;

	if( userp(ob) || undefinedp(my["max_gin"]) ) {
		if( my["age"] <= 14 ) my["max_gin"] = 100;
		else if( my["age"] <= 20 ) my["max_gin"] = 100 + (my["age"] - 14) * 20;
		else if( my["age"] <= 30 ) my["max_gin"] = 220;
		else if( my["age"] <= 60 ) my["max_gin"] = 220 - (my["age"] - 30) * 5;
		else my["max_gin"] = 70;
		if( my["max_atman"] > 0 ) my["max_gin"] += my["max_atman"] / 4;
	}
	if( userp(ob) || undefinedp(my["max_kee"]) ) {
		if( my["age"] <= 14 ) my["max_kee"] = 100;
		else if( my["age"] <= 20 ) my["max_kee"] = 100 + (my["age"] - 14) * 20;
		else my["max_kee"] = 220;
		if( my["max_force"] > 0 ) my["max_kee"] += my["max_force"] / 4;
	}
	if( userp(ob) || undefinedp(my["max_sen"]) ) {
		if( my["age"] <= 30 ) my["max_sen"] = 100;
		else my["max_sen"] = 100 + (my["age"] - 30) * 5;
		if( my["max_mana"] > 0 ) my["max_sen"] += my["max_mana"] / 4;
	}

	ob->set_default_object(__FILE__);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);
}

mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}
