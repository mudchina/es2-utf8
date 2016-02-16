#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()

{
     set_name("拂尘", ({"whip"}) );
     set_weight(1000);
     if( clonep() )
             set_default_object(__FILE__);
     else {
     set("unit", "柄");
     set("long", "一柄以藤木为柄, 马尾为丝的拂尘\n");
     set("value", 100);
     set("martial", "wood");
     set("wield_msg", "$N从背后的腰带抽出一柄$n握在手中。\n");
     set("unwield_msg", "$N将手中的$n放下斜插在背后的腰带上。\n");
     }
     init_whip(10);
    
     setup();
}
