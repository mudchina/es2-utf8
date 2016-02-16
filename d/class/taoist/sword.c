// sword.c

#include <ansi.h>

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name( HIR "咒剑王□" NOR, ({ "sword" }) );
	set_weight(7000);
	set("unit", "把");
	set("long",
		"这是一把桃木雕成的古剑，闻起来有一股香味，剑身刻著许\多你从未见过的咒\n"
		"文，只有剑柄部份有两个依稀可以辨认的篆字：「 王 □ 」\n");
	set("value", 18000);
	set("material", "steel");
	init_sword(44);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");

// The setup() is required.

	setup();
}
