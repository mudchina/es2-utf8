// Mon  08-21-95

#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("铁锤", ({ "hammer" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "一把老旧的铁锤, 上面坑坑凹凹的....");
        set("unit", "把");
		set("material", "iron");
	}

	init_hammer(10);
	setup();
}
