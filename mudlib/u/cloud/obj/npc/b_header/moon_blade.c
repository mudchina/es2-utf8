// moon_blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("霜月刀", ({ "moon blade", "blade" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        
"这是一把耀眼的利刃，刀背上面带有道凹槽，乃是陈剑秋的成名武器。\n");
                        
                set("value", 1800);
                set("material", "steel");
                set("wield_msg", 
"只听见「飕」地一声，$N的手中已经多了一把$n。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }
        init_blade(40);
        setup();
}
 
