// robe.c

inherit EQUIP;

void create()
{
	set_name("八卦道袍", ({ "robe" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
                set("long", "一件胸前绣有八卦的黄色道袍。\n");
		set("value", 8000);
		set("material", "cloth");
		set("armor_type", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/spells", 5);
	}
}
