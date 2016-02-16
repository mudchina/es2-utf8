// black_suit.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("夜行衣", ({ "black suit", "suit" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 1100);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/id", ({"figure"}) );
		set("armor_prop/name", ({"黑衣人"}) );
		set("armor_prop/short", ({"黑衣人(figure)"}) );
		set("armor_prop/long", ({
			"一个身穿黑色夜行衣，看起来神秘兮兮的家伙。\n"
		}) );
	}
	setup();
}
