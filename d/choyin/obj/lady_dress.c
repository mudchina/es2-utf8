// lady_dress.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("轻罗绸衫", ({ "lady dress", "dress" }) );
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一件有钱人家的小姐穿著的衣物，手工相当细致。\n");
		set("unit", "件");
		set("value", 700);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 5);
		set("female_only", 1);
	}
	setup();
}

