#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("柳玉刀", ({ "blade","yu-blade" }) );
       set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 500);
                set("material", "iron");
                set("long", "这是一柄纤细的柳玉刀，轻薄短小。\n");
                set("wield_msg", "$N抽出一柄纤细的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
        }
        init_blade(27);
        setup();
}
