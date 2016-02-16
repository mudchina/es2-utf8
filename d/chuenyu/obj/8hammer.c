// sixhammer.c

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("八楞玄铁锤", ({ "eighthammer" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把八楞玄铁锤，沉甸甸的。\n");
                set("value", 800);
                set("material", "blacksteel");
                set("wield_msg", "$N拿出一把$n，试了试重量，然後握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_hammer(20);
        setup();
}
