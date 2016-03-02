// boots.c

#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("熊皮短靴", ({ "bearskin boots", "boots" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 400);
		set("material", "fur");
		set("unit", "双");
		set("armor_prop/armor", 7);
		set("armor_prop/defense", 1);
	}
	setup();
}
