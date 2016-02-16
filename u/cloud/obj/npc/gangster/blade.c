// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("鬼头刀", ({ "blade" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 700);
		set("material", "iron");
		set("long", "这种厚重的大刀，强盗喜欢用，份量大约十斤重。\n");
		set("wield_msg", "$N抽出一把表面斑驳的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插回腰间。\n");
	}
	init_blade(25);
	setup();
}
