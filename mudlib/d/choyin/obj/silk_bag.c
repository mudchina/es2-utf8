// silk_bag.c

inherit ITEM;

void create()
{
	set_name("紫罗鸳鸯荷包", ({ "silk bag", "bag", "###silk bag###" }));
	set_weight(200);
	set_max_encumbrance(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个绣工十分精细的紫色丝绸荷包，上面绣著一对鸳鸯。\n");
		set("value", 1200);
		set("material", "silk");
	}
}
