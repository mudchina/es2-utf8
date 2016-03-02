
#include <armor.h>
inherit NECK;

void create()
{
        set_name( "黄金令牌" , ({ "gold ream","ream" }) );
         set("long", "一个闪闪发亮的黄金令牌，上有一些图腾标志。\n");
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 3000);
                set("no_drop", 1);
                set("material", "gold");
                set("armor_prop/unarmed", 1);
                set("armor_prop/dodge", 1);
        set("wear_msg", "$N将$n拿出戴在颈子上。\n");
        }
        setup();
}
