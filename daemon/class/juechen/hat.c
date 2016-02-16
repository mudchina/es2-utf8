//hat.c

#include <ansi.h>

inherit EQUIP;

void create()
{
    set_name( MAG"紫金冠" NOR, ({ "gold hat", "hat" }));
        set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "顶");
                set("value", 12000);
                set("material", "cloud");
                set("armor_type", "head");
                set("armor_prop/spells", 5);
	        set("armor_prop/intelligence", 3);
        }
}

