// pink_cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("淡青长袍", ({ "green cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这件淡青长袍绸衫上面绣著几只黄鹊，闻起来还有一股淡香。\n");
		set("unit", "件");
		set("value", 26000);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 5);
	}
	setup();
}

