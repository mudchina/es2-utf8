// watcher_hat.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("水烟阁司事帽", ({ "watcher hat", "hat" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("value", 200);
		set("armor_prop/attack", -2);
		set("armor_prop/armor", 3);
	}
	setup();
}
