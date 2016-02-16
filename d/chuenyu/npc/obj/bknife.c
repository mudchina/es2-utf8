// knife.c

#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("碧玉刀", ({ "knife" }) );
        set_weight(6500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把当年张家老祖宗退隐时皇上赐的宝刀");
                set("value", 20000);
                set("material", "crimsonsteel");
        }
        init_dagger(40);

        set("wield_msg", "$N从腰间抽出一把亮闪闪的$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n别在腰间。\n");


        setup();
}

