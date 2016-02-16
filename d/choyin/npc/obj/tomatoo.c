// cake.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("山药蛋", ({ "tomatoo"}) );
	set_weight(130);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "圆溜溜的山药蛋，忒新鲜。\n");
		set("unit", "个");
		set("value", 25);
		set("food_remaining", 5);
		set("food_supply", 10);
	}
}
