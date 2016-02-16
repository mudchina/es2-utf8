// sword.c

#include <ansi.h>

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name( HIR "咒剑王□" NOR, ({ "sword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        
"这是一把桃木雕成的古剑，闻起来有一股香味，剑身刻著许多你从未见过的咒\n"
                        "文，只有剑柄部份有两个依稀可以辨认的篆字：「 王 □ 
」\n");
                set("value", 18000);
                set("material", "steel");
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }

        init_sword(44);
        setup();

        set("weapon_prop/spirituality", 30);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int damage;

        if( victim->is_ghost() ) {
                if( random(me->query("max_atman")) > 
(int)victim->query("atman")/2 ) {
                        damage = me->query_spi();
                        victim->receive_wound("gin", damage);
                        me->receive_heal("gin", damage);
                        me->receive_heal("kee", damage);
                        me->receive_heal("sen", damage);
                        return HIY 
"王□剑发出一股金色的罡气，流遍$N的全身。\n" NOR;
                }
                return random(me->query_spi());
        }
}
 
