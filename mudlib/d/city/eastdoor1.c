// eastdoor1.c
#include <room.h>

inherit ROOM;

string look_notice();

void create()
{
        set("short", "京师东一门");
        set("long", @LONG
你来到京师的东一门。城门口十来个手持刀枪的士兵正在检查
过往的行人。经常有一些富丽堂皇的大车缓缓驶入城来，那是京师
的官宦人家出游归来。城墙上有一张陈旧的布告(notice)。东边是
城外，风景如画。西边是京师的街道。
LONG
        );

        set("item_desc", ([
                "notice": (: look_notice :),
                "door": (: look_door, "out" :),
        ]) );

        set("exits", ([
//                "out"          : __DIR__"e1soad1",
                "west"          : __DIR__"street9" ]) );

        set("objects", ([
                __DIR__"npc/guard" : 3, ]) );  

        create_door("out", "城门", "enter");
        setup();
}

string look_notice()
{
     return "布告经风吹日晒，字迹已经不可分辨了。\n";
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
