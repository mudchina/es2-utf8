// cloth.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "四喜绸缎庄");
        set("long", @LONG
四喜绸缎庄是京师中的一家刚刚开业的专营衣帽的商店。店内
顾客稀少，显得店铺空荡荡的。柜台上凌乱地摊着几匹绸缎。绸缎
庄的老板出去进货了，只有老板娘空守店铺。据说这家店铺很有来
历。一般的地痞也很少到店中闹事。
    店堂上挂有一块崭新的招牌(sign)。
LONG
        );
        set("exits", ([
                "east"   :  __DIR__"street6" ]) );

        set("objects", ([
              __DIR__"npc/clother.c" : 1, ]) );

        set("item_desc", ([
                "sign": (: look_sign :),]) );

        setup();

}

string look_sign(object me)
{
        return RED"匾上三个大字：闯名堂\n"NOR;
}

