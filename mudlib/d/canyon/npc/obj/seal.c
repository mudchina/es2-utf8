//seal.c

#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("[1;33m印鉴[0m",({ "seal" }) );
	set("long", "泛著黄光，上面刻著镇国大将军。\n");
	set("unit", "颗");
	set("base_weight", 200);

	set("no_sell", 1);
}


