// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("乌檀木刀", ({ "ebony blade", "blade" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把黑黝黝的乌檀木刀，闻起来有一股淡淡的香气。\n");
		set("value", 600);
		set("material", "wood");
		set("wield_msg", "$N「飕」地一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	init_blade(37);
	setup();
}
