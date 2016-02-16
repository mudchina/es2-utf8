// dead_leech.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("死岩蛭", ({ "dead leech", "leech" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一条死得硬梆梆的岩蛭，要不是灰扑扑的颜色，看起来倒是有些像是腊肠。\n");
		set("unit", "只");
		set("value", 0);
		set("food_remaining", 3);
		set("eat_func", (: eat_tonic :) );
		set("tonic", ([ "force": 1, "max_mana": 60 ]) );
		set("food_supply", 70);
	}
	call_out("decay", 240);
}

static void decay()
{
	say("死岩蛭发出一股难闻的恶臭，烂掉了 ... \n");
	destruct(this_object());
}
