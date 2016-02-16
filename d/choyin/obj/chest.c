// chest.c

inherit ITEM;

void create()
{
	set_name("桃木箱", ({ "peach chest", "chest" }) );
	set_weight(1400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个刻工相刚精细的桃木箱，也许\是用来装首饰用的。\n");
		set("value", 300);
		set("material", "wood");
	}
}
