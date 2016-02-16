//passport.c
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("官府通令",({ "passport" }) );
        set("long", "这是一枚黝黑的令牌，上面刻有官府印章。\n");
        set("unit", "枚");
        set("base_weight", 200);
        set("no_sell", 1);
}

