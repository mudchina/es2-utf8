// eastdoor2.c
#include <room.h>

inherit ROOM;

string look_notice();

void create()
{
        set("short", "京师东二门");
        set("long", @LONG
这里是京师的东二门。城门上插着几面旗帜，标志了本门的守
城将领。城楼里坐着几个将军打扮的人，城墙上有一张刚刚粘贴上
去的布告(notice)，一群人正围着观看。东边是城外，西边是京师
的街道。
LONG
        );

        set("item_desc", ([
                "notice": (: look_notice :),
                "door": (: look_door, "out" :),
        ]) );

        set("exits", ([
//                "out"          : __DIR__"e2soad1",
                "west"          : __DIR__"street10" ]) );

        set("objects", ([
                __DIR__"npc/guard" : 3 ,]) );  

        create_door("out", "城门", "enter" );
        setup();
}

string look_notice()
{
     return "布告上写著：辑拿要犯----於兰天武。\n";
}

int valid_leave(object me,string dir)
{
        if ( dir=="out" &&
                ( !(string) me->query("marks/京师")
                || !(string) me->query("marks/令牌") ) ) {
                tell_object (me, "京师守城兵说道：没有官府通令，任何人不能出入京师。\n");
                return notify_fail("出城方向的路被京师守城兵挡住了。\n");
                }

        if (me->query("marks/令牌")) {
                ::valid_leave(me,dir);
                me->set("marks/令牌", 0);
                return 1;
                }

        return ::valid_leave(me,dir);
}

