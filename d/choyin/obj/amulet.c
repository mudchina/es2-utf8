// amulet.c

#include <armor.h>

inherit NECK;

void create()
{
	set_name("平安符", ({ "amulet" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个用红线绑著的平安符，据说可以避邪。\n");
		set("material", "paper");
		set("value", 60);
		set("armor_prop/karma", 1);
		set("armor_prop/composure", 1);
		set("armor_prop/defense", -5);
	}
	setup();
}
