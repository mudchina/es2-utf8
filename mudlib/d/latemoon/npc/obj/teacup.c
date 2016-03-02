inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("玉瓷茶杯", ({ "tea cup","cup" }));
        set_weight(1000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("long",
"这是一杯香味浓郁上等好茶。是招待贵宾品茗的。\n"
 "你闻了闻，好香好香哦!\n");
                set("unit", "杯");
                set("value", 20);
                set("max_liquid", 5);
        }
        set("liquid", ([
        	"name" : "金轩茶",
        	"remaining" : 5,
        	"type" : "water"
        ]) );
        set("liquid_type", "water");
        setup();
}

