// token.c

inherit ITEM;

void create()
{
	set_name("杀手令牌", ({ "token", "###token###" }));
	set_weight(200);
	set_max_encumbrance(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个黑木作的杀手令牌，上面刻著火焰的图腾标志。\n");
		set("value", 1200);
		set("material", "wood");
	}
}
