// glaive.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("鬼头刀", ({ "glaive" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 1500);
		set("material", "steel");
		set("long", "这是一把沈重的鬼头刀，刀柄上雕著 一个丑陋可怖的鬼头正裂开了嘴大笑。\n");
		set("wield_msg", "$N抽出一把背厚刃薄的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	init_blade(45);
	setup();
}
