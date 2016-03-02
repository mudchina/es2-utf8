// snake_sandal.c

#include <ansi.h>

inherit EQUIP;

void create()
{
	set_name( GRN "穿花蛇影鞋" NOR, ({ "snake sandals", "sandals" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 8000);
		set("material", "cloth");
		set("armor_type", "feet");
		set("armor_prop/armor", 2);
		set("armor_prop/dodge", 2);
	}
}
