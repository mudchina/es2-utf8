// Room: /d/snow/jiulou_2f.c

inherit ROOM;

void create()
{
        set("short", "太白酒楼二楼");
        set("long", @LONG
你走上了太白酒楼的二楼，酒楼的雅座便设于此。大凡有来头
的客人都到此饮酒作乐。在此经常可以遇上一些达官贵族，一些为
做官的富家子弟就来此打进阶的消息。墙边有一道楼梯通往一楼的
茶座。
LONG
        );
        set("exits", ([ 
		"down":		__DIR__"jiulou",
        ]));

/*        set("objects", ([
                __DIR__"npc/waiter":       1,
                ]));
*/
        setup();
}

