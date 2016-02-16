// houndbane.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name( GRN "妖刀狗屠" NOR, ({ "houndbane blade", "houndbane", "blade" }) );
	set_weight(17000);
	set("unit", "把");
	set("long", "这是一把暗绿色的鬼头刀，拿在手中沈甸甸地。\n");
	set("value", 4200000);
	set("material", "crimsonsteel");
	init_blade(96);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「飕」地一声抽出一把背厚刃薄的$n握在手中。\n");
	set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");

// The setup() is required.

	setup();
}
