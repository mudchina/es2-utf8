inherit ITEM;
inherit F_FOOD;

void create()
{
     set_name("杏仁糖", ({ "sugar" }));
    set_weight(100);
    if( clonep() )
            set_default_object(__FILE__);
    else {
          set("long", "一粒杏仁糖，最适宜作喜糖不过了。\n");
          set("unit", "粒");
          set("value", 50);
          set("food_remaining", 4);
          set("food_supply", 60);
     }
}

