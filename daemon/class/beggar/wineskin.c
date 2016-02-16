// soulimpaler.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name( HIW "邪剑穿灵" NOR, ({ "soulimpaler", "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把血红色的的长剑，份量大约有十来斤左右。\n");
		set("value", 4000000);
		set("material", "crimsonsteel");
		set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入背後的剑鞘。\n");
	}
	init_sword(80);
	setup();
}
