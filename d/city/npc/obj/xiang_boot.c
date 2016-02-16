#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("象皮战靴", ({ "elephant boots","boots" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 12000);
                set("armor_prop/armor", 15);
                set("armor_prop/dodge", 5);
        }
        setup();
}
