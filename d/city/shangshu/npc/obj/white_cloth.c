// pink_cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("月白色长裙", ({ "white cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "简简单单的一套月白色长裙，上面并没有什么装饰，但总给人一种天外仙子的感觉。\n");
		set("unit", "件");
		set("value", 600);
		set("material", "cloth");
//		set("armor_prop/armor", 1);
		set("armor_prop/personality", 4);
		set("female_only", 1);
	}
	setup();
}

