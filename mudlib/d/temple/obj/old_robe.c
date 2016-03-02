// old_robe.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("旧道袍", ({"old robe","robe"}) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一件补了又补, 洗到泛白的旧道袍\n");
		set("unit", "件");
		set("armor_prop/armor", 1);
		set("armor_prop/dodge", -1);
	}
	setup();
}
