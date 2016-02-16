//old_sword.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( HIG "古 剑" NOR, ({ "old sword", "sword"}));
	set_weight(800);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",@LONG
行云流水，如劲风之竹，气聚于锋，如晦如明，斯行于技，缓动而
瞬攻，乃徐如林，急如风，不动如山，侵略如火。
LONG
		);
		set("value", 100);
		set("material", "铜");
		set("skill", ([
		"name" :		"sword",
			"exp_required" :  2500,
            "sen_cost" : 20,
                    "difficulty" : 15,
            "max_skill" : 50
		]) );
        set("replica_ob", __DIR__"cola");
	}
}
		
