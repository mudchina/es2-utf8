// hat.c

inherit EQUIP;

void create()
{
	set_name("碧玉冠", ({ "jade hat", "hat" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("long", "一顶镶著一块碧玉的道冠。\n");
		set("value", 2000);
		set("material", "cloth");
		set("armor_type", "head");
		set("armor_prop/armor", 1);
		set("armor_prop/spells", 3);
	}
}
