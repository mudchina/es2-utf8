
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name( HIW "追风剑" NOR, ({ "windsword", "sword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把淡青色的的长剑，看上去锋利异常。\n");
                set("value", 1000000);
                set("material", "crimsonsteel");
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入剑鞘。\n");
		set("weapon_prop/attack",5);
		set("weapon_prop/courage",10);
        }
        init_sword(70);
        setup();
}

