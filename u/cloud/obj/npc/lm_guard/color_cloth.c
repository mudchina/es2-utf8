// color_cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("舞蝶彩衫", ({ "color cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这件淡绿色的绸衫上面绣著几只彩蝶，煞是好看。\n");
		set("unit", "件");
		set("value", 800);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 2);
		set("female_only", 1);
	}
	setup();
}

