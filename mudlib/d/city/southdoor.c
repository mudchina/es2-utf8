// southdoor.c
#include <room.h>

inherit ROOM;

string look_notice(object me);

void create()
{
        set("short", "京师南门");
        set("long", @LONG
这是京师的南门。高大的城门正上“京师南门”几个大字格外
显眼。城墙上贴着几张官家布告(notice)。西北方是京师的监狱，
关押着一些要犯，因此这里的官兵们也戒备森严。南边是城外，不
时走来几个赴京赶考的举子。北边就是京师，一个灯红酒绿的地方。
LONG
        );

        set("item_desc", ([
                "notice": (: look_notice :),
                "door": (: look_door, "out" :),
        ]) );

        set("exits", ([
//                "out"          : __DIR__"ssoad1",
                "north"          : __DIR__"street17" ]) );

        set("objects", ([
                __DIR__"npc/guard" : 3 ,]) );  

        create_door("out", "城门", "enter");
        setup();
}

string look_notice(object me)
{
       if( wizardp(me) )
                return "告示上写著：悬赏捉拿灵儿、阿泰。\n";
        else
                return "告示上写著：今年文武大选。\n";
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

