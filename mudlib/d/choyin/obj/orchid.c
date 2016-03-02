inherit ITEM;

void create()
{
        set_name("寒谷幽兰", ({ "orchid" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "株");
                set("long", "一株寒谷幽兰，散发着淡淡的香气, 你似乎在晚月庄闻到过.\n");
                set("material", "paper");
                set("value", 10000);
        }
        setup();
}

