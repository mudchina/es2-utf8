
#include <armor.h>
inherit HEAD;

void create()
{
        set_name( "银翅金簪" , ({ "clasp" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("value", 1500);
                set("material", "gold");
                set("armor_prop/armor", 1);
        set("wear_msg", "$N将$n拿出插在头发上。\n");
        }
        setup();
}
