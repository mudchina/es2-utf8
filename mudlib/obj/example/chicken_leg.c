// chicken_leg.c

#include <weapon.h>

inherit HAMMER;
inherit F_FOOD;

void create()
{
	set_name("烤鸡腿", ({ "chicken leg", "chicken", "leg" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一枝烤得香喷喷鸡腿，你还犹豫什麽？准备胃液吧。\n");
		set("unit", "根");
		set("value", 30);
		set("food_remaining", 4);
		set("food_supply", 40);
		set("wield_msg", "$N抓起一根$n，握在手中当武器。\n");
		set("material", "bone");
	}
	init_hammer(1);
	setup();
}

int finish_eat()
{
	if( !query("weapon_prop") ) return 0;
	set_name("啃得精光的鸡腿骨头", ({ "bone" }) );
	set_weight(150);
	set("long", "一根啃得精光的鸡腿骨头。\n");
	return 1;
}
