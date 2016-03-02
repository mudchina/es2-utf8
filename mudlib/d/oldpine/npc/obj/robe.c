// robe.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("太阴八卦袍", ({ "robe" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 10000);
		set("material", "cloth");
		set("armor_prop/armor", 2);
		set("armor_prop/spells", 3);
	}
	setup();
}
