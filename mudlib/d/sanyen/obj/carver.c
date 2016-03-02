// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
    set_name("菜刀", ({ "carver" }) );
    set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 300);
		set("material", "iron");
        set("long", "一把不很利的菜刀, 不过拿来切菜砍肉还是绰绰有馀的。\n");
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插入腰间的牛皮刀套中。\n");
	}
    init_blade(10);
	setup();
}
