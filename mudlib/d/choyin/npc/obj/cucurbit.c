// cucurbit.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("糖葫芦", ({ "sugar cucurbit", "cucurbit", "sugar" }) );
	set_weight(180);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一串看起来就让人垂涎欲滴的糖渍葫芦。\n");
		set("unit", "串");
		set("value", 40);
		set("food_remaining", 4);
		set("food_supply", 50);
	}
}
