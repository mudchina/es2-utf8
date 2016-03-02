inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("女儿红", ({"wine"}));
        set_weight(20000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("long",
   "这是一坛香味浓郁的陈年老酒，是存给待嫁女儿喝的酒。\n"
   "你闻了闻，好香好香哦!你有点想喝它 (drink)\n");
                set("unit", "坛");
                set("value", 20);
                set("max_liquid", 30);
        }
        set("liquid", ([
        	"name" : "红酒",
        	"remaining" : 30,
        	"drunk_bonus" : 5,
        	"type" : "alcohol"
        ]) );
        setup();
}

