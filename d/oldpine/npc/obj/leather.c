// leather.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("皮衣", ({ "leather" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 200);
		set("material", "leather");
		set("unit", "件");
		set("armor_prop/armor", 5);
	}
	setup();
}
