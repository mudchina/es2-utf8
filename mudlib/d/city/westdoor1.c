// southdoor.c
#include <room.h>

inherit ROOM;

string look_notice();

void create()
{
        set("short", "京师西一门");
        set("long", @LONG
你来到京师的西一门。城墙上贴着几张官家布告(notice)。东
北方是大相国寺，不时传来几声钟声。西边是城外，抬头可见远处
连绵的群山。东边就是京师的街道了。
LONG
        );

        set("item_desc", ([
                "notice": (: look_notice :),
                "door": (: look_door, "out" :),
        ]) );

        set("exits", ([
//                "out"          : __DIR__"w1soad1",
                "east"          : __DIR__"street14" ]) );

        set("objects", ([
                __DIR__"npc/guard" : 3 ,]) );  

        create_door("out", "城门", "enter" );
        setup();
}

string look_notice()
{
    return "布告上写著：近来有土匪出没，望行人小心。\n";
}

int valid_leave(object me,string dir)
{
        if ( dir=="out" &&
                ( !(string) me->query("marks/京师")
                 && !(string) me->query("marks/令牌") ) ) {
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
