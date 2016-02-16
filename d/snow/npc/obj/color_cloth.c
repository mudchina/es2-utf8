// color_cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("艳红绸衫", ({ "cloth cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"一件大红色的女子衣衫，看起来有点鲜艳得过火。\n");
		set("unit", "件");
		set("value", 500);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 1);
		set("female_only", 1);
	}
	setup();
}

