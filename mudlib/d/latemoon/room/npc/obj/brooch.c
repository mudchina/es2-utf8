
#include <armor.h>
inherit NECK;

void create()
{
        set_name( "钻石胸针", ({ "brooch diamond","brooch" }) );
        set("long","这是一个用钻石镶成的美丽胸饰。\n");
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 1500);
                set("material", "gold");
                set("armor_prop/armor", 2);
        set("wear_msg", "$N将$n从袖袋中拿出别在胸前衣饰上。\n");
        }
        setup();
}
