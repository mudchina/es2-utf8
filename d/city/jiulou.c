// jiulou.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "太白酒楼");
        set("long", @LONG
你走到了一家大酒楼里。四周的装饰金壁辉煌，令人眼花缭乱，连餐
具的做工也极讲究，不愧是京城的第一大酒楼。酒楼的菜肴是远近闻名的
，在这经常可以看到一些达官贵族，据连当今皇上也曾微服来此以一饱口
福。
LONG
        );

        set("exits", ([
                "east":		__DIR__"street5",
		"up":		__DIR__"jiulou_2",
		]) );

        set("objects", ([
                __DIR__"npc/waiter" : 	1,
		__DIR__"npc/boss":	1,
		]) );
        setup();
}


