inherit ITEM;
inherit F_FOOD;

void create()
{
     set_name("脆皮烤鸭", ({ "duck","food" }));
    set_weight(1000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
          set("long", "这是一只看了都会流口水的、香喷喷的烤鸭。\n");
          set("unit", "只");
          set("value", 50);
          set("food_remaining", 5);
          set("food_supply", 80);
     }
}


