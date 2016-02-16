// slumber_drug.c

inherit POWDER;

void create()
{
	set_name("蒙汗药", ({ "slumber drug", "drug" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"这是寻常的绿林盗贼用来作案的蒙汗药，你可以把它倒(pour)在\n"
			"酒水之中使用。\n" );
		set("unit", "包");
		set("base_value", 20);
		set("base_unit", "份");
		set("base_weight", 30);
	}
	set_amount(1);
}

int drink_drug(object ob)
{
	this_player()->apply_condition("slumber_drug",
		(int)this_player()->query_condition("slumber_drug") + 100 );
	return 0;
}


