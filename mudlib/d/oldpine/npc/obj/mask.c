// mask.c

inherit EQUIP;

void create()
{
	set_name("蒙面头罩", ({ "mask" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 600);
		set("material", "cloth");
		set("armor_type", "mask");
		set("armor_prop/id", ({"maskman"}) );
		set("armor_prop/name", ({"蒙面人"}) );
		set("armor_prop/short", ({"蒙面人(maskman)"}) );
		set("armor_prop/long", ({
			"这个人头上戴著蒙面头罩，八成准备干什么坏事。\n"
		}) );
	}
}
