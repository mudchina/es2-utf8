// weapon.c
#include <room.h>
inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "京师武器店");
        set("long", @LONG
这里是江湖中人人所向往的京师武器店。店铺宽敞，红砖铺地。
四周的墙壁上挂满了各式的刀剑。东边的武器架上的枪戟的反光令
你睁不开眼。靠北墙的大柜台一尘不染，几个伙计正在忙碌。
    靠近店门的地方有一块金字招牌(sign)。
LONG
        );
        set("exits", ([
                "south"   :  __DIR__"street9" ]) );

        set("objects", ([
              __DIR__"npc/weaponor" : 1, ]) );
        
        set("item_desc", ([
                "sign": (: look_sign :),]) );

        setup();

}

string look_sign(object me)
{
        return "招牌写著：京师武器店专营各式武器。\n";
}

