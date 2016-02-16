// red_hat.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("鲜红金乌冠", ({ "crimson hat", "hat" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("long", "这是水烟阁武士常戴的红色圆顶帽，帽缘镶著一圈金线。\n");
		set("value", 800);
		set("armor_prop/attack", 2);
		set("armor_prop/defense", -2);
		set("armor_prop/armor", 4);
	}
	setup();
}
