// zasui.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("熟杂碎", ({ "fragment" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "可以吃的杂碎\n");
		set("unit", "斤");
		set("value", 50);
       		set("food_remaining", 2);
		set("food_supply", 30);
        	set("material", "blood");
	}

	setup();
}

