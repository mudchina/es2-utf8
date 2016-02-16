// hat.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("青铜道冠", ({"copper hat", "hat"}) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一顶青铜道冠\n");
		set("unit", "顶");
		set("value", 500);
		set("material", "copper");
		set("armor_prop/armor", 1);
		set("armor_prop/magic", 1);
	}
	setup();
}
