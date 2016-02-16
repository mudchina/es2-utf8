
#include <armor.h>
inherit NECK;

void create()
{
        set_name( "护身符", ({ "amulet" }) );
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 100);
                set("material", "paper");
                set("armor_prop/armor", 2);
                set("armor_prop/spells", 1);
        set("wear_msg", "$N将$n拿出戴在颈子上。\n");
        }
        setup();
}
