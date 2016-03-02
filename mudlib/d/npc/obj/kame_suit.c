// kame_suit.c

inherit EQUIP;

void create()
{
	set_name("龟仙派武道服", ({ "kame suit", "suit" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一件印有龟仙派标记的武道服，又轻又耐穿。\n");
		set("unit", "件");
		set("material", "cloth");
		set("armor_type", "cloth");
		set("armor_prop/armor", 2);
		set("armor_prop/attack", 2);
	}
}
