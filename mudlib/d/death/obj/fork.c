// fork.c

#include <weapon.h>

inherit FORK;

void create()
{
	set_name("七股钢叉", ({ "steel fork" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把沈重的大钢叉，七根尖刺发出黑黝黝的光芒。\n");
		set("value", 5100);
		set("material", "steel");
	}
	init_fork(62);

	setup();
}
