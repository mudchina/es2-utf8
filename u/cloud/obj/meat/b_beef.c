// beef.c

inherit ITEM;

void create()
{
        set_name("生牛肉", ({ "beef" }) );
        set_weight(800);
	set("long", "看样子是牛的后腰，但是生肉, 不知能不能吃。\n");
	set("unit", "挂");
	set("value", 70);
        set("material", "rib");

        setup();
}


	
