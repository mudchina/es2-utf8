// wuqing_sword.c"
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
    set_name( HIW"无情剑" NOR,({"cool sword","sword"}));
        set_weight(4500);
        if( clonep() )
                set_default_object(__FILE__);
        else{
                set("unit", "把");
        set("long", "剑锋寒气逼人，剑身发出异样的青光。\n");
                set("value", 24000);
                set("material", "异类金属");
        set("wield_msg", "$N「唰」地一声抽出一把寒气逼人的$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        set("replica_ob", "/obj/weapon/longsword");
    }
        init_sword(45);
        setup();
}

