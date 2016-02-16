// ruler.c

#include <ansi.h>
#include <weapon.h>

inherit DAGGER;

void create()
{
	set_name( "量衣尺", ({ "ruler" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把量衣用的尺子，比一般的宽些。\n");
		set("value", 30);
		set("material", "wood");
		set("wield_msg", "$N拿出一把$n抄在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_dagger(2);
	setup();
}
