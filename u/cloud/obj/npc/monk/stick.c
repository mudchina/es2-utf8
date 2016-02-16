// stick.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name( "僧棍", ({ "monk stick", "stick" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条又粗又长僧棍，表面已被磨得十分光滑。\n");
		set("value", 100);
		set("material", "wood");
		set("wield_msg", "$N拿出一根$n抄在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_staff(13);
	setup();
}
