// tea_leaf.c

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("紫花瓣儿", ({ "purple flower", "flower" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "迷人的紫色瓣儿，发出一股淡淡的香气。\n");
                set("unit", "把");
                set("base_unit", "片");
                set("base_weight", 1);
                set("base_value", 1);
        }
        set_amount(7);
        init_throwing(2);
        setup();
}
