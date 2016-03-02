// tea_leaf.c

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("鸡毛", ({ "feather" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","用来清除灰尘的鸡毛\n");
                set("unit", "把");
                set("base_unit", "片");
                set("base_weight", 1);
                set("base_value", 1);
        }
        set_amount(30);
        init_throwing(1);
        setup();
}
