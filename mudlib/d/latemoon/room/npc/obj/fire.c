
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("火摺", ({ "fire" }) );
    set("unit", "个");
    set("long","这是一个可以生火的火摺");
    set_weight(50);
    setup();
}
