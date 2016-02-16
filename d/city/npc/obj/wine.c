inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("状元红", ({"wine"}));
        set_weight(20000);
        if( clonep() )
            set_default_object(__FILE__);
          else {
        	set("long", "这是一坛香味浓郁的陈年老酒，是专待状元高中时喝的酒。\n");
                set("unit", "坛");
                set("value", 350);
                set("max_liquid", 30);
        }
        set("liquid", ([
                "name" : "红酒",
                "remaining" : 30,
                "drunk_bonus" : 7,
                "type" : "alcohol"
        ]) );
        setup();
}

