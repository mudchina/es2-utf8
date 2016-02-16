// boots.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "李记鞋店");
        set("long", @LONG
这里是京师中最大的一家鞋店。店主姓李，历经几代，已是百
年老店。店铺挺大，弥漫着一种特殊皮革的气味。大柜台后面的架
子上放满了各式的皮靴。店中几个伙计正在忙碌。
    店门口有一块金字招牌(sign)。
LONG
        );
        set("exits", ([
                "south"   :  __DIR__"street11" ]) );

        set("objects", ([
              __DIR__"npc/shoer.c" : 1, ]) );

        set("item_desc", ([
                "sign": (: look_sign :),]) );

        setup();

}

string look_sign(object me)
{
        return HIY "专卖各式鞋。\n"NOR;
}

