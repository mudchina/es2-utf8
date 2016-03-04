// northdoor.c
#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "京师北门");
        set("long", @LONG
这是京师的北门，若干年前曾经遭到异族的攻打，因而显得有
些陈旧。城门正上方清析可见当朝名家书写的“京师北门”几个金
字，城墙上贴着几张告示(sign)。这里是罪犯逃往北方的必经之地，
官兵们戒备森严，动不动就截住行人盘问。一条笔直的青石板大道
向南北两边延伸。北边是郊外，骑马的、座轿的、走路的，行人匆
匆涌入京师。南边是城里，隐约传来阵阵的喧闹声。
LONG
        );

        set("item_desc", ([
                "sign": (: look_sign :),
                "door": (: look_door, "out" :),
        ]) );

        set("exits", ([
                "north"            : __DIR__"nroad1",
                "south"          : __DIR__"street16" ]) );

        set("objects", ([
                __DIR__"npc/guard" : 3, ]) );  

        create_door("out", "城门", "enter");
        setup();
}

string look_sign(object me)
{
       if( wizardp(me) )
                return "告示上写著：捉拿灵儿、阿泰。\n";
        else
                return "告示上隐约写著几个人名，但都模糊不可分辨了。\n";
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
