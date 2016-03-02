// leather.c

#include <armor.h>

inherit SURCOAT;

void create()
{
	set_name("狼皮披风", ({ "wolfskin cloak", "cloak" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 1200);
		set("material", "fur");
		set("unit", "件");
		set("armor_prop/armor", 8);
		set("armor_prop/attack", 1);
	}
	setup();
}
