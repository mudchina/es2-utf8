// leather_boot.c

#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("牛皮靴", ({ "leather boots", "boots" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("material", "leather");
		set("value", 300);
		set("armor_prop/dodge", 1);
		set("armor_prop/armor", 4);
	}
	setup();
}
