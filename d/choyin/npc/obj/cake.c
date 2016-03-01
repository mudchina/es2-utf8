// cake.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("大饼", ({ "big cake", "cake" }) );
	set_weight(130);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个香喷喷、热腾腾的大烧饼。\n");
		set("unit", "个");
		set("value", 25);
		set("food_remaining", 5);
		set("food_supply", 60);
	}
}
