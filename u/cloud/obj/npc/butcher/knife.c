// knife.c

#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("解牛刀", ({ "knife" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把很锋利的钢刀, 就是短了些。\n");
                set("value", 200);
                set("material", "steel");
        }
        init_dagger(10);

        set("wield_msg", "$N从腰间抽出一把亮闪闪的$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n别在腰间。\n");

// The setup() is required.

        setup();
}

