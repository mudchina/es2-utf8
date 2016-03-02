//old_sword.c

#include <ansi.h>

inherit ITEM;
//inherit F_UNIQUE;

void create()
{
    set_name( "过招要旨", ({ "parrybook","pbook" }) );
	set_weight(800);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",@LONG
这是一本介绍过招时如何拆招卸力的书籍。
对练武人来说是本不可多得的珍宝。
LONG
		);
		set("value", 100);
    		set("material", "paper");
		set("skill", ([
        		"name" :        "parry",
            		"exp_required" :  15000,
            		"sen_cost" : 30,
                    	"difficulty" : 25,
            		"max_skill" : 50
			]) );
        	set("replica_ob", __DIR__"cola");
		}
}
		
