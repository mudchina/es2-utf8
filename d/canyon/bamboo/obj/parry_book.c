//old_sword.c

#include <ansi.h>

inherit ITEM;
inherit F_UNIQUE;

void create()
{
    set_name( "悟疾风劲竹书", ({ "book" }) );
	set_weight(800);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",@LONG
直竹贵地生，风吹动不止，起迄中空立，随风飘不定，斯乃劲风竹

						   柳淳风
LONG
		);
		set("value", 100);
        set("material", "paper");
		set("skill", ([
        "name" :        "parry",
            "exp_required" :  20000,
            "sen_cost" : 30,
                    "difficulty" : 15,
            "max_skill" : 50
		]) );
        set("replica_ob", __DIR__"cola");
	}
}
		
