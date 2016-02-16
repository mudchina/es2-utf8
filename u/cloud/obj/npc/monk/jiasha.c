// jiasha.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("青布袈裟", ({ "monk cloth", "cloth" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这件青色的袈裟洗得很是干净。\n");
		set("unit", "件");
		set("value", 100);
		set("material", "cloth");
		set("armor_prop/armor", 2);
		set("male_only", 1);
	}
	setup();
}

