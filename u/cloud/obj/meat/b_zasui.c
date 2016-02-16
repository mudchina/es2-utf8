// beef.c

inherit ITEM;

void create()
{
        set_name("杂碎", ({ "fragment" }) );
        set_weight(100);
	set("long", "看样子是牛或狗的杂碎，但是生的, 好象不能吃。\n");
	set("unit", "堆");
	set("value", 20);
        set("material", "blood");

        setup();
}


	
