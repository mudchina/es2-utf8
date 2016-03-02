// black_vest.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("黑丝背心", ({ "black vest", "vest" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"这件黑丝背心看起来黑黝黝地不怎麽起眼，而且比一般的衣服\n"
			"重了些，你仔细一看，它的质料非金非帛，却不知是什麽东西\n"
			"织成的。\n");
		set("unit", "件");
		set("value", 14000);
		set("material", "blacksilk");
		set("armor_prop/armor", 30);
		set("armor_prop/armor_vs_force", 70);
		set("armor_prop/attack", -5);
	}
	setup();
}

/*int query_autoload() { return 1; }*/
