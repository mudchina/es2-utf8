// jingang_staff.c
#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name( HIY "金刚杖" NOR, ({ "jingang staff", "staff" }) );
        set_weight(13000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long", "这是一条紫铜杖，杖的两端似乎封这密文。\n");
                set("value", 80000);
                set("material", "brass");
                set("wield_msg", "$N「唰」地一声抽出一条$n擎在手中。\n");
                set("unequip_msg", "$N将手中的$n拄在地上。\n");
                set("weapon_prop/spells",10);
                set("weapon_prop/dodge",-5);
        }
        init_staff(78);
        setup();
}

