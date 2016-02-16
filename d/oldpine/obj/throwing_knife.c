// throwing_knife.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("飞刀", ({ "throwing knife", "knife" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "些");
		set("base_unit", "把");
		set("base_weight", 300);
		set("base_value", 80);
		set("material", "iron");
		set("long",	"飞刀是一种十分轻、锐利的匕首，用来当作暗器使用。\n");
	}
	set_amount(1);
	init_throwing(20);
	setup();
}
