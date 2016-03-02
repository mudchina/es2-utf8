#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("鹿皮小靴", ({ "deer boots","boots" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 2000);
                set("armor_prop/armor", 2);
                set("armor_prop/dodge", 1);
        }
        setup();
}
