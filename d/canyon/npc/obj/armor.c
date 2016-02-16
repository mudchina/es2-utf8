// cloud_armor

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name( "青铜战盔",({ "armor" }) );
	set_weight(42000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "copper");
		set("value",2000);
		set("armor_prop/armor", 35);
		set("armor_prop/dodge", -10);
	}
	setup();
}

