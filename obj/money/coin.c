// coin.c

inherit MONEY;

void create()
{
	set_name("钱", ({"coin", "coins", "coin_money" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "coin");
		set("long", "这是流通中单位最小的货币，约要一百文钱才值得一两银子。\n");
		set("unit", "些");
		set("base_value", 1);
		set("base_unit", "文");
		set("base_weight", 1);
	}
	set_amount(1);
}

