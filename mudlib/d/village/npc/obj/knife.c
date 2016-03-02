// Mon  08-21-95

#include <weapon.h>

inherit BLADE;

void create()
{
    set_name("菜刀", ({ "kitchen knife", "knife" }) );
    set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","一把旧旧的菜刀, 刀口几乎被磨平了, 不过还颇具有杀伤力.\n");
        set("unit", "把");
		set("material", "iron");
	}
    init_blade(7);
	setup();
}

