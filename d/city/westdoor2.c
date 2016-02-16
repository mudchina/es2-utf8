// westdoor2.c
#include <room.h>

inherit ROOM;

string look_notice();

void create()
{
        set("short", "京师西二门");
        set("long", @LONG
你来到京师的西二门，西二门虽不如京师的其他几个城门高大。
但高高的城墙也非一般人所能攀越，城墙上贴着几张布告(notice)。
西边是城外，据说一直往西就可到达一个仙境。东边就是京师的街
道了。
LONG
        );

        set("item_desc", ([
                "notice": (: look_notice :),
                "door": (: look_door, "out" :),
        ]) );

        set("exits", ([
//                "out"          : __DIR__"w2soad1",
                "east"          : __DIR__"street13" ]) );

        set("objects", ([
                __DIR__"npc/guard" : 3 ,]) );  

        create_door("out", "城门", "enter" );
        setup();
}

string look_notice()
{
     return "布告上写著：行人出入需缴纳一两黄金。\n";
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

