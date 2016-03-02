// grass.c

inherit ITEM;

void create()
{
        set_name("忘忧草", ({ "grass" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "棵");
                set("long", "一棵翠绿色的小草，发着晶莹的光芒和醉人的香味。\n");
                set("material", "paper");
                set("value", 10000);
        }
        setup();
}

