// sorrowfire.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("焦殇剑", ({ "sword of sorrowfire", "sword", "sorrowfire" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把通体黝黑，又带著一丝焦味的铁剑。\n");
		set("value", 7800);
		set("material", "iron");
		set("wield_msg", "$N拿出一把黝黑的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_sword(74);
	setup();
}
