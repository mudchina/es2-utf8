// guihua.c

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("红桂花", ({ "osmanthus flower", "flower" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "才摘的桂花，发出阵阵淡淡的幽香。\n");
                set("unit", "把");
                set("base_unit", "粒");
                set("base_weight", 1);
                set("base_value", 1);
        }
        set_amount(10);
        init_throwing(1);
        setup();
}       
