#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"丝罗巾" NOR, ({ "hankie" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "卷");
                set("long",
                        
"这卷罗巾由上等丝绸编成，绣了一幅幅美女图。个个体态轻盈，翩然\n"
"起舞。每一曲舞步姿态美妙迷人，旁题著舞曲名称与步法。\n");
                set("value", 100);
                set("material", "silk");
                set("no_drop", 1);
                set("skill", ([
                        "name":                 "move",
                  "exp_required": 5000,
                        "sen_cost":             
30,
                        "difficulty":   20,
                        "max_skill":    50
                ]) );
        }
}
