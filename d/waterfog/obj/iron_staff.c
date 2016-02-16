// iron_staff.c

#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("黑铁杖", ({ "iron staff", "staff" }) );
	set_weight(70000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "这条黑铁杖光看就知道非常沈重，拿在手里才知道比想像中更重。\n");
		set("value", 2800);
		set("material", "iron");
		set("wield_msg", "$N拿出一条黑黝黝的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_staff(54);
	setup();
}
