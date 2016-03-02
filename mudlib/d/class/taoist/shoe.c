// shoe.c

inherit EQUIP;

void create()
{
	set_name("七星翻云靴", ({ "cloudy shoes", "shoes" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("value", 6000);
		set("material", "cloth");
		set("armor_type", "feet");
		set("armor_prop/armor", 2);
		set("armor_prop/dodge", 4);
	}
}
