// rainwhip.c
#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
        set_name( HIM "烟雨鞭" NOR, ({ "rain whip", "whip" }) );
        set_weight(17000);
        if( clonep() )
                set_default_object(__FILE__);
        else {

	        set("unit", "条");
	        set("value", 20000);
       		set("material", "leather");
	}

	init_whip(28);

        set("wield_msg", "$N从腰间解下一条$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n缠回腰间。\n");

        setup();
}

