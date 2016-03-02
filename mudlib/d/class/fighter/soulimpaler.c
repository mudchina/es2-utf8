// soulimpaler.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name( HIW "邪剑穿灵" NOR, ({ "soulimpaler", "sword" }) );
	set_weight(7000);
	set("unit", "把");
	set("long", "这是一把血红色的的长剑，份量大约有十来斤左右。\n");
	set("value", 4000000);
	set("material", "crimsonsteel");
	init_sword(80);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unequip_msg", "$N将手中的$n插入背后的剑鞘。\n");

// The setup() is required.

	setup();
}
