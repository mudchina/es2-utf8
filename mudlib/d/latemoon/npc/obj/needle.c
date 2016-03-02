#include <ansi.h>
#include <weapon.h>

inherit THROWING;

void create()
{
    set_name(HIC "绣花针" NOR, ({"needle" }) );
     if ( clonep() )
              set_default_object(__FILE__);
     else {
             set("long", "一种上等铁做成的绣花针\n");
          set("unit", "些");
          set("base_unit", "根");
          set("base_weight", 30);
          set("base_value", 100);
          set("material", "iron");
     }
     set_amount(1);
     init_throwing(30);
     setup();
}
