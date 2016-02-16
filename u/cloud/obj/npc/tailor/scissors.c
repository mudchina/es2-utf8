// scissors.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name( "裁衣剪", ({ "scissors" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把长而锋利的剪刀。\n");
		set("value", 100);
		set("material", "iron");
		set("wield_msg", "$N拿出一把$n抄在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_sword(15);
	setup();
}
