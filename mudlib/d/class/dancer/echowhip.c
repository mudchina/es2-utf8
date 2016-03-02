// echowhip.c

#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
	set_name( HIM "魔鞭翩珑" NOR, ({ "echo whip", "whip" }) );
	set_weight(17000);
	set("unit", "条");
	set("value", 100000);
	set("material", "leather");
	init_whip(37);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N从腰间解下一条$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n缠回腰间。\n");

// The setup() is required.

	setup();
}
