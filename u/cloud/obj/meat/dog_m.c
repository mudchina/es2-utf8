// dog_m.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("狗肉", ({ "dog" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "哇! 好香的狗肉! 不吃还等什么?\n");
		set("unit", "斤");
		set("value", 60);
        	set("food_remaining", 3);
		set("food_supply", 60);
        	set("material", "rib");
	}

        setup();
}

int finish_eat()
{
        set_name("狗骨头", ({ "rib" }) );
        set_weight(250);
        set("long", "啃得精光的狗骨头。\n");
        return 1;
}

	
