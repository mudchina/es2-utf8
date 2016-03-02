// pink_cloth.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("玫瑰花", ({ "flower", "rose" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一朵热情,奔放的红玫瑰.\n");
		set("unit", "朵");
		set("value", 15);
		set("material", "grass");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

