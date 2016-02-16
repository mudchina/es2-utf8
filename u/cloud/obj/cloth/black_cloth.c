//black_cloth.c
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("夜行衣", ({ "black cloth", "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一件夜行人用来掩藏行踪的黑色紧身衣。\n");
                set("unit", "件");
                set("value", 800);
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("armor_prop/dodge", 1);
                set("armor_prop/personality", -1);
        }
        setup();
}


