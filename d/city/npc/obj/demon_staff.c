// demon_staff.c
#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name( RED "天魔杵" NOR, ({ "demon staff", "staff" }) );
        set_weight(25000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把暗红色、两丈多长的巨杵。\n");
		set("value", 20000);
                set("material", "crimson gold");
        }
        init_staff(50);
        setup();
}

