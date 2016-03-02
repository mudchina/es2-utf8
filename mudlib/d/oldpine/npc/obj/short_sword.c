// short_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("短剑", ({ "short sword", "sword" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 300);
		set("material", "iron");
		set("long",
			"一把粗制滥造的短剑，把手部份用布缠绕了好几圈以防止武器脱手。\n");
	}
	init_sword(15, SECONDARY);
	setup();
}
