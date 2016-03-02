// ginseng.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("人参", ({ "ginseng" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一根约食指长的人参，据说常吃这种补品可以延年益寿。\n");
		set("unit", "根");
		set("value", 3000);
		set("food_remaining", 1);
		set("eat_func", (: eat_tonic :) );
		set("tonic", ([ "atman": 5, "max_atman": 150 ]) );
		set("food_supply", 30);
	}
}
