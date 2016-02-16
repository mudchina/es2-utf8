#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name( "蛇鳞皮鞭", ({ "snakewhip" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("value", 500);
                set("material", "skin");
                set("rigidity", 100);
        }
        init_whip(15);

        set("wield_msg", "$N从腰间摸出一条$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n束在腰间。\n");
        setup();
}

