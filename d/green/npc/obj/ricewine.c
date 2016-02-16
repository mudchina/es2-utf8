// Mon  08-21-95

inherit ITEM;
inherit F_LIQUID;

void create()
{
    set_name("陶壶", ({ "pottery" }) );
    set_weight(1000);
    if (clonep())
        set_default_object(__FILE__);
    else {
            set("long","一个手工制造的陶壶, 看起来年代久远.\n");
            set("unit","个");
            set("value",0);
            set("max_liquid",10);
    }
    set("liquid", ([
        "type" : "alcohol",
        "name" : "米酒",
        "remaining" : 7,
        "drunk_apply" : 7,
    ]) );
}

