// long_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("长剑", ({ "long sword", "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 700);
		set("material", "iron");
		set("long",
			"一把粗制滥造的长剑，把手部份用布缠绕了好几圈以防止武器脱手。\n");
	}
	init_sword(25);
	setup();
}
