
#include <weapon.h>

inherit STAFF;

void create()
{
    set_name("竹扫把", ({"bamboo broom", "broom"}) );
    set_weight(1000);
    if( clonep() )
             set_default_object(__FILE__);
    else {
          set("unit", "把");
          set("long", "一把快秃了头的竹扫把。\n");
          set("value", 50);
          set("material", "bamboo");
          set("wield_msg", "$N拿起一把$n握在手中。\n");
          set("unwield_msg", "$N放下手中的$n。\n");
         } 
   init_staff(3);

   setup();
}
