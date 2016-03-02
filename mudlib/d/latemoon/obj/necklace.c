#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
        set_name(HIM "珍珠项链" NOR, ({ "necklace" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "串");
                set("value", 10000);
                set("material", "pearl");
                set("armor_prop/armor", 5);
                set("armor_prop/spells",5);
                set("wear_msg", "$N拿出一串$n戴在颈子上。\n");
        }
        setup();
}
