// armor1.c
#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
        set_name( HIY "紫铜战盔" NOR,({ "armor" }) );
        set_weight(42000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "copper");
                set("value",10000);
                set("armor_prop/armor", 30);
                set("armor_prop/dodge", -8);
        }
        setup();
}

