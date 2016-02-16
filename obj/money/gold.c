// gold.c

inherit MONEY;

void create()
{
	set_name("黄金", ({"gold", "ingot", "gold_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "gold");
		set("long", "黄澄澄的金子，人见人爱的金子，啊～～金子！\n");
		set("unit", "些");
		set("base_value", 10000 );
		set("base_unit", "两");
		set("base_weight", 37);
	}
	set_amount(1);
}

