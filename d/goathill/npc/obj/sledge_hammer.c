// sledge_hammer.c

#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("大金槌", ({ "sledge hammer", "hammer" }) );
	set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 1600);
		set("material", "steel");
		set("long", "一把极其沈重的大槌，要挥动这样的武器非得有过人的膂力不可。\n");
		set("weapon_prop/attack", -4);
		set("weapon_prop/defense", 5);
	}
	init_hammer(45, SECONDARY);
	setup();
}
