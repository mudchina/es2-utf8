#include <room.h>

inherit ROOM ;

void create()
{
        set("short","绝地");
        set("long",@LONG
这是一块绝地,四周没有任何出口,你不禁急得要哭了出来,忽然,你发现
远方有一块大石(stone)动了一下,走近一看,似乎可以推(push)一下。
LONG
);

        set("outdoors","green");
        set("no_clean_up",0);
        setup();
//        replace_program(ROOM);
}

void init()
{
//        ::init();
        add_action("do_push","push");
}

int do_push(string arg)
{
        object me;
        
        if ( !arg || arg != "stone" )
                return notify_fail("你要推什麽?\n");
        
        me=this_player();
        
        if ( ((int)me->query("force") < 560) ||
             ((int)me->query("max_force") < 560) ||
             ((int)me->query("force_factor") < 40 ) ) { 
                tell_object(me, "你出力不太够喔！\n");
                return 1;
        }

        me->receive_damage("gin",20);
        me->receive_damage("kee",60);
        me->receive_damage("sen",20);
        message_vision("$N用力推活动的大岩石,大岩石动了一下\n",me);
        
        if ( random(3) == 0 ) {
                message_vision("大岩石滚开了,$N从大岩石后面的小洞钻了出去\n",me);
                this_player()->move(__DIR__"entrance");
                message("vision","$N从山壁上的一个洞口钻了出来\n",environment(me),me);
        	tell_room(__DIR__"closed","风一吹,大岩石又滚了回来,把洞口又封住了\n");
                return(1);
        }
        return(1);
}


