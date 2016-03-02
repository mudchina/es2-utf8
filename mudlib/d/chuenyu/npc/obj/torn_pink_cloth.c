// pink_cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("破烂的粉红布衫", ({ "pink cloth", "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这件粉红色的布衫上沾满了暗红色的血迹。\n");
                set("unit", "件");
                set("value", 200);
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", -3);
                set("female_only", 1);
        }
        setup();
}

