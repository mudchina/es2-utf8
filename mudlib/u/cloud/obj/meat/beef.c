// beef.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("熟牛肉", ({ "beef" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "哇! 好香的牛肉! 不吃还等什么?\n");
		set("unit", "斤");
		set("value", 100);
        	set("food_remaining", 3);
		set("food_supply", 80);
        	set("material", "rib");
	}
        setup();
}

int finish_eat()
{
        set_name("牛肋骨", ({ "rib" }) );
        set_weight(200);
        set("long", "啃得精光的牛肋。\n");
        return 1;
}

	
