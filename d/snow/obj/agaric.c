// agaric.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("灵芝", ({ "magical agaric", "agaric" }) );
	set_weight(35);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"灵芝是一种相当昂贵的药材，但是许\多方士都把灵芝当成重要的\n"
			"药品。\n");
		set("unit", "株");
		set("value", 4000);
		set("food_remaining", 1);
		set("eat_func", (: eat_tonic :) );
		set("tonic", ([ "mana": 5, "max_mana": 150 ]) );
		set("food_supply", 30);
	}
}
