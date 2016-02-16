inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("水饺", ({ "boiled dumplings","food" }));
    set_weight(100);
    if( clonep() )
            set_default_object(__FILE__);
    else {
          set("long", "这是一个手工细腻的水饺，看起来很好吃。\n");
          set("unit", "个");
          set("value", 50);
          set("food_remaining", 2);
          set("food_supply", 30);
     }
}


