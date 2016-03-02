#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
        set_name( HIG "绿罗裙" NOR, ({ "skirt" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                 set("value", 2100);
                set("material", "cloth");
                set("armor_prop/armor", 4);
        set("wear_msg", "$N将$n拿出系在腰上。\n");
        }
        setup();
}
