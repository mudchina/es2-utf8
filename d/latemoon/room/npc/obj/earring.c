
#include <armor.h>
inherit HEAD;

void create()
{
        set_name( "耳环", ({ "earring" }) );
        set("long","这是一串用宝石镶串成的闪亮耳环。\n");
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "串");
                set("value", 1500);
                set("material", "gold");
                set("armor_prop/armor", 1);
        set("wear_msg", "$N将$n拿出穿戴在耳朵上。\n");
        }
        setup();
}
