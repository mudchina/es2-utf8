
#include <armor.h>
inherit FINGER;

void create()
{
        set_name( "冰玉戒指" , ({ "ice ring", "ring" }) );
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 3000);
                set("material", "gold");
                set("armor_prop/unarmed", 2);
                set("armor_prop/armor", 1);
                set("armor_prop/spells", 2);
        set("wear_msg", "$N将$n拿出戴在右手无名指上。\n");
        }
        setup();
}
