#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("绣花鞋", ({ "flower boots","boots" }) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 2500);
                set("armor_prop/armor", 3);
        }
        setup();
}
