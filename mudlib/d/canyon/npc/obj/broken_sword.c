// sword:__DIR__"obj/broken_sword.c" 破残奇剑一把

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
//inherit F_UNIQUE;

void create()
{
    set_name( HIW"ψ破 残 奇 剑ψ" NOR,({"broken sword","sword"}));
	set_weight(4500);
	if( clonep() )
		set_default_object(__FILE__);
	else{
		set("unit", "把");
       	set("long", "剑锋处缺了一角，缺角处发出异样白光的奇剑。\n");
		set("value", 4000);
		set("material", "异类金属");
        set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        set("replica_ob", "/obj/weapon/longsword");
    }
	init_sword(65);
	setup();
}

